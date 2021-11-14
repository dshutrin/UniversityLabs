#include <list>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct book{
    int count, ukd;
    bool on_hands = false;
    char name[50], autor[50];

    void get(){
        if (count > 0){
            book::count--;
            book::on_hands = true;
        }
    }

    void back(){
        if (book::on_hands = true){
            book::count++;
            book::on_hands = false;
        }
    }

    void info(){
        cout << "Name: " << book::name << endl << "Autor: " << book::autor << endl << "UKD: " << book::ukd << endl;
        cout << "Count: " << book::count << endl << "On hands: " << book::on_hands << endl << endl;
    }

};

int main(){

    int count;
    char var[100];
    cout << "Enter book count in libriary: ";
    count = system("main.py");

    list<book> books;

    for (int i = 0; i < count; i++){
        book my_book;
        cout << "Enter book name: ";
        cin.getline(my_book.name, 50);
        cout << "Enter book autor: ";
        cin.getline(my_book.autor, 50);
        cout << "How many of these books are there in the library?: ";
        my_book.count = system("main.py");
        cout << "Enter book ukd: ";
        my_book.ukd = system("main.py");
        cout << endl;
        books.push_back(my_book);
    }

    for (book &it: books){
        cout << it.name << endl;
        cout << it.autor << endl;
        cout << it.ukd << endl;
        cout << it.count << endl << endl;
    }

    string menu = "1) Get book\n2) Return a book\n3) Look info from books\n4) Exit";

    int mode = 0;
    while (mode != 4){
        cout << "Choice program mode:\n" << endl << endl << menu << endl << endl;
        cin >> mode;

        if (mode == 1){
            int n_ukd;
            for (book &it: books)
                it.info();
            cout << "Enter book ukd: ";
            cin >> n_ukd;

            int flag = 0;
            for (book &it: books){
                if (it.ukd == n_ukd){
                    it.get();
                    flag = 1;
                    cout << "You geted book: " << it.name << endl;
                }
            }
            
            if (flag == 0){
                cout << "Not found this book!" << endl;
            }
        }

        if (mode == 2){
            int n_ukd;
            for (book &it: books)
                it.info();
            cout << "Enter book ukd: ";
            cin >> n_ukd;

            int flag = 0;
            for (book &it: books){
                if (it.ukd == n_ukd){
                    it.back();
                    flag = 1;
                    cout << "You return book: " << it.name << endl;
                }
            }

            if (flag == 0){
                cout << "Not found this book!" << endl;
            }
        }

        if (mode == 3){
            for (book &it: books)
                it.info();
        }
    }
}