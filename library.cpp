#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Book
{
private:
    string title;
    string author;
    string ISBN;
    bool available;
public:
    Book(string t,string a,string i): title(t),author(a),ISBN(i),available(true){}
    string getTitle() const
    {
        return title;
    }
    string getauthor() const
    {
        return author;
    }
    string getISBN() const
    {
        return ISBN;
    }
    bool getavailable() const
    {
        return available;
    }
    void checkout()
    {
        available=false;
    }
    void returnBook()
    {
        available=true;
    }
};
class library
{
private:
     vector<Book>books;
public:
     void addBook(const Book& book)
     {
        books.push_back(book);
     }
     vector<Book>searchBook(const string & query)
     {
        vector<Book> results;
        for(const auto& book:books)
        {
            if (book.getTitle()==query || book.getauthor()==query || book.getISBN() == query)
            {
                results.push_back(book);
            }
        }
        return results;
     }
     void checkoutBook(const string & ISBN)
     {
        for(auto & book : books)
        {
            if (book.getISBN()==ISBN && book.getavailable())
            {
                book.checkout();
                cout<<"Book checked out successfully"<<endl;
                return;
            }
        }
        cout<<"Book not found or not available for checkout"<<endl;
     }
     void returnBook(const string & ISBN)
     {
        for(auto & book : books)
        {
            if (book.getISBN()==ISBN && !book.getavailable())
            {
                book.returnBook();
                cout<<"Book returned successfully"<<endl;
                return;
            }
        }
        cout<<"Book not found already returned"<<endl;
     }
};
int main()
{
    library library;
    library.addBook(Book("project management"," s. paul","5656"));
    library.addBook(Book("compiler design"," r. sant","4565"));
    library.addBook(Book("machine learning"," s. namel","5935"));
    cout<<"welcome to library management system!"<<endl;
    int choice;
    string searchQuery,ISBN;
    while(true)
    {
    cout<< "\n menu"<<endl;
    cout <<"1. search Books"<<endl;
    cout <<"2. checkout Book"<<endl;
    cout <<"3. return book "<<endl;
    cout <<"4. Exit"<<endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
        cout<<"enter title,author, or ISBN to search";
        cin.ignore();
        getline(cin,searchQuery);
        {
            vector<Book>results=library.searchBook(searchQuery);
            if(results.empty())
            {
                cout<<"matching Book"<<endl;
                for (const auto & book : results)
                {
                    cout<<"_ "<<book.getTitle()<<"by"<<book.getauthor()<<"(ISBN "<<book.getISBN()<< ")" <<endl;
                }
            }
        }
        break;
    case 2:
        cout<<"enter the ISBN of book to checkout";
        cin>>ISBN;
        library.checkoutBook(ISBN);
        break;
    case 3:
        cout<<"enter the ISBN of book to return";
        cin>>ISBN;
        library.returnBook(ISBN);
        break;
    case 4:
        cout<<"Existing program.."<<endl;
        return 0;
    default:
    cout<<"invalid choice. please try again"<<endl;
     }
    }
    return 0;
}           