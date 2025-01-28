#ifndef SCREEN_H
#define SCREEN_H
#include "Book.h"
#include <limits>
class Screen
{
 public:
     static void Welcome(){
       cout<<"**********************\n**********************\nWelcome to our Bank\n";
     }
     static void Menu1(){
       cout<<"**********************\n**********************\n";
       cout<<"Main menu:\n";
       cout<<"1-Adding Books.\n";
       cout<<"2-Searching Books.\n";
       cout<<"3-Removing Books.\n";
       cout<<"4-Updating Books.\n";
       cout<<"5-Borrowing Books.\n";
       cout<<"6-Returning Books.\n";
       cout<<"7-Displaying Books.\n";
       cout<<"**********************\n**********************\n";
     }
     static int validChoice1(int &choice1){
       string str1;
       while(true){
        getline(cin,str1);
        bool valid=true;
        for(char c:str1){
          if(!isdigit(c)){
             valid=false;
             break;
          }
        }
        if(valid&&!str1.empty()){
            choice1=stoi(str1);
            return choice1;
        }else{
            cin.clear();
            cout<<"\nInvalid input choose a valid number\n";
        }
       }
     }
     static void Choices(int choice){

       switch(choice){
        case 1:
         {
          cout<<"1-Adding Books:\n";
          string title,author;
          Book::AddNewBook(title,author);
          break;
         }
        case 2:
         {
          cout<<"2-Searching Books:\n";
          int id;
          cout<<"\nEnter the id of book you want to search for\n";
          validChoice1(id);
          if(Book::SearchBook(id)){
            cout<<"The book that has id "<<id<<" is found\n";
          }else{
            cout<<"The book that has id "<<id<<" isn't found\n";
          }
          break;
         }
        case 3:
         {
          cout<<"3-Removing Books:\n";
          int id;
          cout<<"\nEnter the id of book you want to remove\n";
          validChoice1(id);
          Book::RemovingBooks(id);
          break;
         }
        case 4:
         {
          cout<<"4-Updating Books:\n";
          int id;
          string title,author;
          Book::updatingBooks(id,title,author);
          break;
         }
        case 5:
         {
          cout<<"5-Borrowing Books:\n";
          int id;
          cout<<"\nEnter the id of the book you want to borrow\n";
          validChoice1(id);
          Book::BorrowingBooks(id);
          break;
         }
        case 6:
         {
          cout<<"6-Returning Books:\n";
          int id;
          cout<<"\nEnter the id of the book you want to return\n";
          validChoice1(id);
          Book::ReturningBooks(id);
          break;
         }
        case 7:
         {
          cout<<"7-Displaying Books:\n";
          Book::DisplayingBooks();
          break;
         }
        default:
          cout<<"\nInvalid entry choice enter a valid number from 1 to 7\n";
          int choice1;
          validChoice1(choice1);
          Choices(choice1);
       }
     }
     static void Menu2(){
       cout<<"**********************\n**********************\n";
       cout<<"1-Return to main menu\n";
       cout<<"2-End Program\n";
       cout<<"Enter 1 or 2\n";
       cout<<"**********************\n**********************\n";
     }
     static void Start(){
       int choice1,choice2;
       string str1,str2;
       bool finish=true;
       Welcome();
       while(finish=true){
       Menu1();
       validChoice1(choice1);
       Choices(choice1);
       Menu2();
       validChoice1(choice2);
        bool check=true;
        if(choice2==1){
            Start();
            break;
        }else if(choice2==2){
           check=true;
          finish=false;
          break;
        }else{
          cout<<"\nInvalid entry choice please enter 1 or 2\n";
          validChoice1(choice2);
          check=false;
       }
       }
     }
};
#endif // SCREEN_H
