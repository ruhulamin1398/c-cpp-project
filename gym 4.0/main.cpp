#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int temp;
void HomePage();
void Search();


#include "Structure.h";
#include "AddNew.h";
#include "View.h";
#include "Search.h";
#include "Remove.h"






int main(){
    string password="1234";

    cout<<"\t\t\t\t\t\tWelcome to GYM Management System"<<endl;
    cout<<"Enter Your PassWord"<<" : ";
    string pass;
    cin>>pass;
    while(pass!=password){
        cout<<"\t\t\t\tIncorrect Password!!!!"<<endl<<"\t\t\t\tTry Again"<<" : "<<endl;
        cin>>pass;
    }

    HomePage();








return 0 ;
}


void HomePage(){
    system("cls");
    cout<<"\t\t\t\t\t----- Main Menu -----"<<endl<<endl<<endl;

    cout<<"\t\t1. Add new Trainer/Member"<<endl;
    cout<<"\t\t2. View Trainer/Member"<<endl;
    cout<<"\t\t3. Search Trainer/Member"<<endl;
    cout<<"\t\t4. Remove TrainerMember"<<endl;
    cout<<"\t\t5. Close App"<<endl<<endl<<endl;
    cout<<"Enter Your Choice"<<" : ";

     switch(getchar())
    {
    case '1':
        AddNew();
        break;
    case '2':
        View();
        break;
    case '3':
        system("cls");
        Search();
        break;
    case '4':
        Remove();
    case '5':
        exit(0);
    default:
        HomePage();
    }

}
