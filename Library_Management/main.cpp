#include <algorithm>
#include <iostream>
using namespace std;

//max size of the library
const int maxSize = 100;
class Book {
    //private variables
    string title;
    string author;
    int pages;
    bool borrowed;

public:
    //default constructor
    Book() {
        title = "";
        author = "";
        pages = 0;
        borrowed = false;
    };
    //constructor overloading, otherwise the compiler won't be able to construct a Book with no arguments
    Book(string title, const string &author, const int pages) {
        this->title = title;
        this->author = author;
        this->pages = pages;
        borrowed = false;
    }
    void borrow() {
        borrowed = true;
    }
    void returnBook() {
        borrowed = false;
    }
    bool isBorrowed() const {
        return borrowed;
    }
    int getPages() const {
        return pages;
    }
    string getTitle() const{
        return title;
    }
    string getAuthor() const {
        return author;
    }
    void printBook() const {
        cout << getTitle() << endl;
        cout << getAuthor() << endl;
    }
};

class Library {
    //private variables
    Book books[maxSize];
    int count;
    void checkIfEmpty();
public:
    //basic constructor which sets the count
    Library() {
        count = 0;
    }
    //adds a book into the array
    bool addBook(const Book &b) {
        if (count >= maxSize) {
            cout << "Library is full" << endl;
            return false;
        }
        //adds a book into the next available spot
        books[count] = b;
        count++;
        return true;
    }
    //list all available books
    void listAllBooks() {
        if (isLibraryEmpty()) {
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
    //borrow a book unless it is already borrowed
    bool borrowedByTitle(string title) {
        if (isLibraryEmpty()) {
            return false;
        }
        for (int i = 0; i < count; i++) {
            //borrow a book if the title matches and the book is not already borrowed
            if (books[i].getTitle() == title && !books[i].isBorrowed()) {
                cout << "Borrowing " << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
                books[i].borrow();
                return true;
            }
            //if it is borrowed, return false
            if (books[i].getTitle() == title && books[i].isBorrowed()) {
                cout << "That book is already borrowed" << endl;
                return false;
            }
        }
        return false;
    }
    //return a book
    bool returnByTitle(string title) {
        if (isLibraryEmpty()) {
            return false;
        }
        for (int i = 0; i < count; i++) {
            //checks whether the book is borrowed
            if (books[i].getTitle() == title && books[i].isBorrowed()) {
                cout << "Borrowing: " << books[i].getAuthor() << endl;
                books[i].returnBook();
                return true;
            }
            //if the book is not borrowed, return false
            if (books[i].getTitle() == title && !books[i].isBorrowed()) {
                cout << books[i].getTitle() << " is not borrowed";
                return false;
            }
        }
        return false;
    }
    //calculates the book with the largest pages
    Book largestBook() const {
        //if the count is 0 return an empty constructor book
        if (isLibraryEmpty()) {
            return Book();
        }
        //if the current book is smaller than the next overwrite the value
        Book largest = books[0];
        for (int i = 1; i < count; i++) {
            if (books[i].getPages() > largest.getPages()) {
                largest = books[i];
            }
        }
        return largest;
    }
    bool isLibraryEmpty() const {
        if (count == 0) {
            cout << "Library is empty" << endl;
            return true;
        }
        return false;
    }
};

void printMenu();

int main() {
    Library library;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {

            case 1: {
                string title, author;
                int pages;

                cout << "Enter title: ";
                cin.ignore();               // remove leftover newline
                getline(cin, title);

                cout << "Enter author: ";
                getline(cin, author);

                cout << "Enter pages: ";
                cin >> pages;

                library.addBook(Book(title, author, pages));
                cout << "Book added.\n";
                break;
            }

            case 2: {
                string title;

                cout << "Enter title to borrow: ";
                cin.ignore();
                getline(cin, title);

                if (library.borrowedByTitle(title))
                    cout << "Borrowed successfully.\n";
                else
                    cout << "Could not borrow.\n";

                break;
            }

            case 3: {
                string title;

                cout << "Enter title to return: ";
                cin.ignore();
                getline(cin, title);

                if (library.returnByTitle(title))
                    cout << "Returned successfully.\n";
                else
                    cout << "Could not return.\n";

                break;
            }

            case 4:
                library.listAllBooks();
                break;

            case 5: {
                Book b = library.largestBook();
                cout << "Largest book:\n";
                b.printBook();
                cout << "Pages: " << b.getPages() << endl;
                break;
            }

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}

void printMenu() {
    cout << "1. Add book" << endl;
    cout << "2. Borrow book by title" << endl;
    cout << "3. Return book by title" << endl;
    cout << "4. List all books" << endl;
    cout << "5. Show largest book (most pages)" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose: ";
}
