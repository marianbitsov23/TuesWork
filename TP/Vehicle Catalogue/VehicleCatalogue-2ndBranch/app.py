from functools import wraps

from flask import Flask
from flask import render_template, request, redirect, url_for, jsonify, send_from_directory, flash, session
from werkzeug import secure_filename
from datetime import datetime

import json
import os, shutil, string, random
import logging

from database import DB

from user import User
from comment import Comment
from sale import Sale
from category import Category

app = Flask(__name__)
app.secret_key = "vehicle catalogue key"

logging.basicConfig(filename = 'info.log', level=logging.DEBUG)
app.logger.disabled = True
log = logging.getLogger('werkzeug')
log.disabled = True

def i_logger(text):
    time_now = datetime.now()
    date = time_now.strftime("%D %T ")
    logging.info(date + text)

def w_logger(text):
    time_now = datetime.now()
    date = time_now.strftime("%D %T ")
    logging.warning(date + text)


def require_login(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        if not session.get('logged_in'):
            return redirect('/login')
        return func(*args, **kwargs)
    return wrapper

@app.route('/')
def main_page():
    if session.get('logged_in'):
        return redirect('/sales_logged_in')
    return redirect('/sales')

@app.route('/user_info')
@require_login
def user_info():
    username = User.find_by_id(session['USERNAME'])
    return render_template('user_info.html', user = User.find_by_username(username))


#SALES METHODS
@app.route('/sales/user_sales')
@require_login
def user_sales():
    sales = Sale.find_by_user_id(session['USERNAME'])
    images = {}
    for sale in sales:
        directory = os.listdir(sale.file_path) 
        file_path = sale.file_path
        images.update({file_path : directory[0]})
    return render_template('library.html', sales = sales, images = images)

@app.route('/sales_logged_in')
@require_login
def sales_logged_in():
    sales = Sale.all()
    images = {}
    for sale in sales:
        directory = os.listdir(sale.file_path) 
        file_path = sale.file_path
        images.update({file_path : directory[0]})
    return render_template('sales_logged_in.html', sales = sales, username = User.find_by_id(session['USERNAME']), images = images, file_path = file_path)

@app.route('/sales/search', methods=['POST'])
def search_sale():
    if request.method == 'POST':
        keyword = request.form['keyword']
        with DB() as db:
            rows = db.execute('''SELECT * FROM sales WHERE 
            (name LIKE ? OR model LIKE ?) ''', ("%" + keyword + "%", "%" + keyword + "%",)).fetchall()
            sales = [Sale(*row) for row in rows]
            images = {}
            for sale in sales:
                directory = os.listdir(sale.file_path) 
                file_path = sale.file_path
                images.update({file_path : directory[0]}) 
            return render_template('searched_sales.html', sales = sales, images = images)

@app.route('/sales')
def list_sales():
    if session.get('logged_in'):
        return redirect('/sales_logged_in')
    sales = Sale.all()
    images = {}
    for sale in sales:
        directory = os.listdir(sale.file_path) 
        file_path = sale.file_path
        images.update({file_path : directory[0]})
    return render_template('sales.html', sales = sales, images = images)

@app.route('/sales/<int:id>')
def show_sale(id):
    sale = Sale.find(id)
    images = os.listdir(sale.file_path)
    sale.file_path = '/' + sale.file_path
    username = session['USERNAME']
    return render_template('sale.html', sale = sale, images = images, username = username)

@app.route('/sales/new', methods=['GET', 'POST'])
@require_login
def new_sale():
    if request.method == 'GET':
        return render_template('new_sale.html', categories = Category.all())
    elif request.method == 'POST':
        letters = string.ascii_lowercase
        direc_path = random.choice(letters)
        direc = request.form['model']
        if request.files['file'].filename == '':
            flash('You forgot to upload in image!')
            return redirect('/sales/new')
        images = request.files.getlist("file")
        os.mkdir("static/images/" + direc + User.find_by_id(session['USERNAME']) + direc_path)
        for img in images:
            img_path = 'static/images/' + direc + User.find_by_id(session['USERNAME']) + direc_path + "/"
            img.save(img_path + img.filename)
        category = Category.find(request.form['category_id'])
        values = (
            None,
            request.form['name'],
            request.form['model'],
            request.form['horsepower'],
            request.form['price'],
            request.form['year'],
            request.form['condition'],
            request.form['mileage'],
            category,
            img_path,
            session['USERNAME']
        )
        Sale(*values).create()

        text = "user id: " + str(session['USERNAME']) + "with username: " + User.find_by_id(session['USERNAME']) + "made a post"
        i_logger(text)

        return redirect('/')

@app.route('/sales/<int:id>/delete', methods=['POST'])
@require_login
def delete_sale(id):
    sale = Sale.find(id)
    shutil.rmtree(sale.file_path)
    with DB() as db:
        db.execute('DELETE FROM comments WHERE sale_id = ?', (sale.id,))
    sale.delete()

    text = "user id: " + str(session['USERNAME']) + "with username: " + User.find_by_id(session['USERNAME']) + "deleted a post"
    i_logger(text)

    return redirect('/')

@app.route('/sales/<int:id>/edit', methods=['GET', 'POST'])
@require_login
def edit_sale(id):
    sale = Sale.find(id)
    if request.method == 'GET':
        return render_template('edit_sale.html', sale = sale, categories = Category.all())
    elif request.method == 'POST':
        sale.name = request.form['name']
        sale.model = request.form['model']
        sale.condition = request.form['condition']
        sale.price = request.form['price']
        sale.mileage = request.form['mileage']
        sale.year = request.form['year']
        sale.horsepower = request.form['horsepower']
        sale.category = Category.find(request.form['category_id'])
        if request.files['file'].filename == '':
            flash('You forgot to upload in image!')
            return redirect(url_for('edit_sale', id = sale.id))
        images = request.files.getlist("file")
        shutil.rmtree(sale.file_path)
        letters = string.ascii_lowercase
        direc_path = random.choice(letters)
        direc = request.form['model']
        os.mkdir("static/images/" + direc + User.find_by_id(session['USERNAME']) + direc_path)
        for img in images:
            img_path = 'static/images/' + direc + User.find_by_id(session['USERNAME']) + direc_path + "/"
            img.save(img_path + img.filename)
        sale.file_path = img_path
        sale.save()

        text = "user id: " + str(session['USERNAME']) + "with username: " + User.find_by_id(session['USERNAME']) + "edited a post"
        i_logger(text)

        return redirect(url_for('show_sale', id = sale.id))


#CATEGORIES METHODS
@app.route('/categories')
def get_categories():
    return render_template("categories.html", categories=Category.all())

@app.route('/categories/new', methods=['GET', 'POST'])
def new_category():
    if request.method == "GET":
        return render_template("new_category.html")
    elif request.method == "POST":
        category = Category(None, request.form["name"])
        category.create()
        return redirect("/categories")

@app.route('/categories/<int:id>')
def get_category(id):
    return render_template("category.html", category=Category.find(id))


@app.route('/categories/<int:id>/delete')
def delete_category(id):
    Category.find(id).delete()
    return redirect("/categories")


#COMMENTS METHODS
@app.route('/comments/new', methods=['GET', 'POST'])
@require_login
def new_comment():
    if request.method == 'POST':
        sale = Sale.find(request.form['sale_id'])
        user_id = session['USERNAME']
        username = User.find_by_id(user_id)
        if not request.form['message']:
            flash('You entered empty comment!')

            text = "user id: " + str(session['USERNAME']) + "with username: " + User.find_by_id(session['USERNAME']) + "tried to comment unsuccessfully"
            w_logger(text)

            return redirect(url_for('show_sale', id=sale.id))
        else:
            values = (None, sale, request.form['message'], user_id, username)
            Comment(*values).create()

        text = "user id: " + str(session['USERNAME']) + "with username: " + User.find_by_id(session['USERNAME']) + "commented successfully"
        i_logger(text)

        return redirect(url_for('show_sale', id=sale.id))

@app.route('/comments/<int:id>/delete', methods=['POST'])
@require_login
def del_comment(id):
    Comment.delete(id)
    sale = Sale.find(request.form['sale_id'])

    text = "user id: " + str(session['USERNAME']) + "with username: " + User.find_by_id(session['USERNAME'])  + "edited a comment"
    i_logger(text)

    return redirect(url_for('show_sale',id = sale.id))

@app.route('/comments/<int:id>/edit', methods=['POST'])
@require_login
def edit_comment(id):
    if not request.form['message']:
        Comment.delete(id)
    else:
        Comment.save(request.form['message'], id)
    sale = Sale.find(request.form['sale_id'])

    text = "user id: " + str(session['USERNAME']) + "with username: " + User.find_by_id(session['USERNAME'])  + "edited a comment"
    i_logger(text)

    return redirect(url_for('show_sale',id = sale.id))    


#REGISTRATION/LOGIN METHODS
@app.route('/edit_user', methods=['POST'])
def edit_user():
    if request.method == 'POST':
        username = User.find_by_id(session['USERNAME'])
        user = User.find_by_username(username)
        user.username = request.form['username']
        user.email = request.form['email']
        if User.find_by_username(user.username):
            flash('This username is already registered!')
            return redirect('/user_info')
        elif User.find_by_email(user.email):
            flash('This email is already registered!')
            return redirect('/user_info')
        elif not request.form['password']:
            flash('You forgot enter your new password!')
            return redirect('/user_info')
        elif not request.form['confirmpassword'] == request.form['password']:
            flash('Wrong confiramtion for password!')

            text1 = "user id: " + str(session['USERNAME']) + "with username: " + User.find_by_id(session['USERNAME']) + "did not confirm password"
            w_logger(text1)

            return redirect('/user_info')
        user.password = User.hash_password(request.form['password'])
        User.save(user)

        text2 = "user id: " + str(session['USERNAME']) + "with username: " + User.find_by_id(session['USERNAME'])  + "made changes to their account"
        i_logger(text2)

        return redirect('/user_info')

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'GET':
        return render_template('register.html')
    elif request.method == 'POST':
        username = request.form['username']
        email = request.form['email']
        if User.find_by_username(username):
            flash('This username is already registered!')
            return render_template('register.html')
        elif not request.form['password'] == request.form['confirmpassword']:
            flash('Incorrect password confirmation!')
            return render_template('register.html')
        elif User.find_by_email(email):
            flash('This email is already registered!')
            return render_template('register.html')
        values = (
            None,
            username,
            User.hash_password(request.form['password']),
            email
        )
        User(*values).create()
        user = User.find_by_username(username)
        session['logged_in'] = True
        session['USERNAME'] = user.id
        return redirect('/')        

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'GET':
        return render_template('login.html')
    elif request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        confirmpassword = request.form['confirmpassword']
        user = User.find_by_username(username)
        if not user or not user.verify_password(password):
            flash('Incorrect login information!')
            
            w_logger("user entered wrong password")

            return render_template('login.html')
        elif not user.verify_password(confirmpassword) == user.verify_password(password):
            flash('Incorrect login information!')
             
            w_logger("user entered wrong credentials")
        
            return render_template('login.html')
        session['logged_in'] = True
        app.logger.info('%s logged in ', user.username)
        session['USERNAME'] = user.id

        text = "user id: " + str(session["USERNAME"]) + "with username: " + User.find_by_id(session['USERNAME']) + "has logged in"
        i_logger(text)

        return redirect('/')

@app.route('/log_out', methods=['POST'])
@require_login
def log_out():
    text = "user id: " + str(session['USERNAME']) + "with username: " + User.find_by_id(session['USERNAME']) + "is logging out"
    i_logger(text)
    session['USERNAME'] = None
    session['logged_in'] = False
    return redirect('/')

if __name__ == '__main__':
    app.run(debug=True)