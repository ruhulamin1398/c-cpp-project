#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;


void Home();
#include "Structure.h";
#include "Movie.h";
#include "Ticket.h";




int main()
{

    cout<<"\t\t\t\t\t\tWelcome to ABC Cinema"<<endl;

    Home();
    return 0 ;
}


void Home()
{
    system("cls");
    cout<<"\t\t\t\t\t----- Main Menu -----"<<endl<<endl<<endl;

    cout<<"\t\t1. Add Movie"<<endl;
    cout<<"\t\t2. Remove Movie"<<endl;
    cout<<"\t\t3. Movie List"<<endl;
    cout<<"\t\t4. Buy Ticket"<<endl;
    cout<<"\t\t5. reserved Tickets"<<endl;
    cout<<"\t\t6. Close App"<<endl<<endl<<endl;
    cout<<"Enter Your Choice"<<" : ";

    switch(getchar())
    {
    case '1':
        addmovie();
    case '2':
        removemovie();
    case '3':
        movies();
        break;
    case '4':
        buy();
        break;
    case '5':
        reserved();
        break;
    case '6':
        exit(0);
    default:
        Home();
    }

}


