


#include<bits/stdc++.h>

#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<time.h>
#define RETURNTIME 15
using namespace std;
map< string ,pair<string , double > >item;
map< string ,pair<string , double > >::iterator it ;
double  total;
 map <string, int > cart;
 map <string, int > :: iterator itr;
void   welcome();
void HomePage();

void Insert();
void Payment();
void View();
void Receipt();
void Sell();


#include "Style.cpp";
#include "Insert.cpp";
#include "View.cpp";
#include "Sell.cpp";






int main() {

    welcome();

    Insert();
    cout<<"Enter Your PassWord"<<" : ";
    string password="1234";
    string pass;
    cin>>pass;
    while(pass!=password) {
        cout<<"\t\t\t\tIncorrect Password!!!!"<<endl<<"\t\t\t\tTry Again"<<" : "<<endl;
        cin>>pass;
    }
    Insert();
    HomePage();
    return 0 ;

}

void  welcome() {
    system("cls");


    gotoxy(1,3);
    cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Welcome to Abasas Super Market \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
    gotoxy(1,5);
    cout<<"\t\t( Scan the barcode or insert it manually )"<<endl;
    gotoxy(0,7);
    {
        int linen=95;
        while(linen--)
            printf("*");
    }
    gotoxy(0,10);
}

void HomePage() {
    system("cls");
    welcome();
    cout<<"\t\t\t\t\t----- Main Menu -----"<<endl<<endl<<endl;

    cout<<"\t\t1. View Product"<<endl;
    cout<<"\t\t2. Sell Product"<<endl;
    cout<<"\t\t3. Close App"<<endl<<endl<<endl;
    cout<<"Enter Your Choice"<<" : ";

    switch(getchar()) {
    case '1':
        system("cls");
        View();
        break;
    case '2':
        system("cls");
        Sell();
        break;
    case '3':
        exit(0);
    default:
        HomePage();
    }

}
