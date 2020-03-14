#include "Service.h"
#include "User.h"
#include "Media.h"
#include "Book.h"
#include "Song.h"
#include "Movie.h"
#include "Game.h"
#include "Bill.h"

int main(){

    Book book("Zaglavie", "Stephen King", 20);
    Song song(5, "Take waht you want", "Post Malone", 10);
    Movie movie(120, 30, "Dirty Grandpa", "Stephen Spilburg", 30);
    Game game(23, "Gta 5", "Unknown", 60);

    vector<string> usermedia;
    usermedia.push_back("book");
    usermedia.push_back("song");
    usermedia.push_back("movie");
    usermedia.push_back("game");

    Bill bill1("01.01.2020", "31.12.2020", 120, 0);
    Bill bill2("11.11.2121", "21.9.2420", 600, 0);


    User biko("Mariyan Bitsov", "marianbitsov23@gmail.com", usermedia, bill1);
    User kiro("Kiro The Rock", "kirotherock@gmail.com", usermedia, bill2);

    vector<User> users;
    users.push_back(biko);
    users.push_back(kiro);

    Service service(users, usermedia);

    service.getUsers();
    service.getUserBill(1);
    service.getUserBill(2);
    service.getPayment();

    cout << service.searchMedia("book") << endl;

    cout << "Status of bill: " <<service.users[0].bill.status << endl;
    cout << "Status of bill: " <<service.users[1].bill.status << endl;

    return 0;
}