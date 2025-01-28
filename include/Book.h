#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
private:
    static int id;
    string title, author;
    bool available=true;
    static vector<Book> bookV;
    int idFinal;

public:
    Book():available(true){}
    Book(string title,string author){
        this->id=id++;
        this->idFinal=id;
        this->title=title;
        this->author=author;
        this->available=true;
    }
    static void setId(int id1){
       id=id1;
    }
    void setTitle(string title){
       this->title=title;
    }
    void setAuthor(string author){
       this->author=author;
    }
    void setAvailable(bool available){
       this->available=available;
    }
    int getId()const{
       return idFinal;
    }
    string getTitle(){
       return title;
    }
    string getAuthor(){
       return author;
    }
    bool getAvailable()const{
       return available;
    }
    static vector<Book>& getBookV(){
       return bookV;
    }
    static Book AddNewBook(string& title,string& author){
       id++;
       int idFinal=id;
       cout<<"\nEnter the Book's title:\n";
       //cin.ignore();
       //cin.clear();
       getline(cin,title);
       cout<<"\nEnter the Book's author:\n";
       getline(cin,author);
       Book book1;
       book1=Book(title,author);
       bookV.push_back(book1);
       return book1;
    }
    static bool SearchBook(int id1){
        for(int i=0;i<bookV.size();i++){
            if(bookV[i].getId()==id1){
                return true;
            }
        }
          return false;
    }
    static void RemovingBooks(int id1){
       for(int i=0;i<bookV.size();i++){
         if(bookV[i].getId()==id1){
        bookV.erase(bookV.begin()+i);
        cout<<"\nThe book that has id: "<<id1<<" is successfully removed\n";
        return;
       }
       }
        cout<<"\nCan't found this id\n";
    }
    static void updatingBooks(int& idFinal,string& title,string& author){
       cout<<"\nEnter the id of the book you want to update\n";
       cin>>idFinal;
      for(auto& b : bookV){
        if(b.getId()==idFinal){
          cout<<"\nEnter the Book's title: \n";
          cin.ignore();
          getline(cin,title);
          cout<<"\nEnter the Book's author:\n";
          getline(cin,author);
          b.setTitle(title);
          b.setAuthor(author);
          cout<<"\nThe book that has id:("<<b.getId()<<") has been update it's title to ("<<b.getTitle()<<") and author to ("<<b.getAuthor()<<")"<<endl;
          return;
      }
      }
      cout<<"\nThe book isn't found\n";
      return;
    }
    static void BorrowingBooks(int id1){
      if(SearchBook(id1)){
          int bookIndex=-1;
          for(int i=0;i<bookV.size();i++){
            if(bookV[i].getId()==id1){
                bookIndex=i;
                break;
            }
          }
        if(bookV[bookIndex].getAvailable()){
            bookV[bookIndex].setAvailable(false);
            cout<<"\nThe book that has id: "<<id1<<" is successfully borrowed\n";
            return;
        }else{
           cout<<"\nThis book is already borrowed\n";
           return;
        }
      }
        cout<<"\nThis book isn't available\n";
        return;
    }
    static void ReturningBooks(int id1){
      if(SearchBook(id1)){
        int bookIndex=-1;
        for(int i=0;i<bookV.size();i++){
            if(bookV[i].getId()==id1){
                bookIndex=i;
                break;
            }
        }
        if(!bookV[bookIndex].getAvailable()){
        bookV[bookIndex].setAvailable(true);
        cout<<"\nThe book that has id: "<<id1<<" is successfully returned\n";
        }else{
        cout<<"\nThe book that has id: "<<id1<<" isn't borrowed and is available\n";
        }
      }else{
        cout<<"\nThis book isn't available\n";
      }
    }
    static void DisplayingBooks(){
      for(int i=0;i<bookV.size();i++){
        cout<<"**********************\n";
        cout<<"Id: "<<bookV[i].getId()<<"\nTitle: "<<bookV[i].getTitle()<<"\nAuthor: "<<bookV[i].getAuthor()<<"\nAvailability: "<<(bookV[i].getAvailable()? "Yes":"NO")<<endl;
        cout<<"**********************\n ";
      }
    }
};

#endif // BOOK_H
