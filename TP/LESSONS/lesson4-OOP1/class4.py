class BookStore: 
    def __init__(self, title, author):
        self.title = title
        self.author = author
        self.__privateMember = "private";
 
    def bookInfo(self):
        print("Book title:", self.title)
        print("Book author:", self.author,"\n")
        print("Private Member inside:", self.__privateMember,"\n")
        
 
# Create a virtual book store
b1 = BookStore("Great Expectations", "Charles Dickens")
 
# call member functions for each object
b1.bookInfo()
print("public member outside:", b1.author,"\n")
print("private member outside:", b1.__privateMember,"\n")