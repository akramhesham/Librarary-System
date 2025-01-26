#ifndef SCREEN_H
#define SCREEN_H
#include "Book.h"
#include <limits>
class Screen
{
 public:
     static void Welcome(){
       cout<<"**********************\n**********************\nWelcome to our Bank\n**********************\n**********************\n";
     }
     static void Menu1(){
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
          cin>>id;
          if(Book::SearchBook(id)){
            cout<<"The book that has id "<<id<<" is found\n";
          }else{
            cout<<"The book that has id "<<id<<"isn't found\n";
          }
          break;
         }
        case 3:
         {
          cout<<"3-Removing Books:\n";
          int id;
          cout<<"\nEnter the id of book you want to remove\n";
          cin>>id;
          Book::RemovingBooks(id);
          break;
         }
        case 4:
         {
          cout<<"4-Updating Books:\n";
          int id;
          string title,author;
          Book::updatingBooks(id,title,author);
          cout<<"\nThe book that has id: "<<id<<" has been update it's title to "<<title<<" and author to "<<author<<endl;
          break;
         }
        case 5:
         {
          cout<<"5-Borrowing Books:\n";
          int id;
          cout<<"\nEnter the id of the book you want to borrow\n";
          cin>>id;
          Book::BorrowingBooks(id);
          break;
         }
        case 6:
         {
          cout<<"6-Returning Books:\n";
          int id;
          cout<<"\nEnter the id of the book you want to return\n";
          cin>>id;
          Book::ReturningBooks(id);
          break;
         }
        case 7:
         {
          cout<<"7-Displaying Books:\n";
          Book::DisplayingBooks();
          break;
         }
/*        default:
          if(cin.fail()){
          cin.clear();
          cin.ignore();
          cout<<"\nInvalid entry choice enter a valid choice\n";
          int choice1;
          cin>>choice1;
          Choices(choice1);
          }*/
       }
     }
     static void validChoice1(int &choice1){
       string str1;
       bool flag=true;
       getline(cin,str1);
       for(char c:str1){
            while(flag){
                if(!isdigit(c)){
                    flag=false;
                }
            }
        if(flag==true&&!str1.empty()){
            choice1=stoi(str1);
            Choices(choice1);
            break;
        }else{
          cout<<"\nInvalid entry choice enter a number from 1 to 7\n";
          validChoice1(choice1);
        }
       }
     }
     static void Menu2(){
       string str2;
       cout<<"1-Return to main menu\n";
       cout<<"2-End Program\n";
       cout<<"Enter 1 or 2\n";
       getline(cin,str2);
       cout<<endl;
     }
     static void Start(){
       int choice1,choice2;
       string str1,str2;
       bool finish=true;
       Welcome();
       while(finish=true){
       Menu1();
       validChoice1(choice1);
        cout<<"\nDo you want to return to main menu or end the program\n";
        Menu2();
        for(char c:str2){
            if(isdigit(c)){
              choice2=stoi(str2);
            }else{
              cout<<"\nInvalid entry choice please enter 1 or 2\n";
              Menu2();
            }
        }
        if(choice2==1){
            Start();
        }else if(choice2==2){
          finish=false;
        }else{
              cout<<"\nInvalid entry choice please enter 1 or 2\n";
              Menu2();
        }
       }
     }
};
#endif // SCREEN_H
