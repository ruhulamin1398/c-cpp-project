
#include<bits/stdc++.h>
using namespace std;
 int n,i, TotalPlayer, LuckyNumber, MembersPoint[101],MaxInput, MinInput,  MembersInput, TotalRound,Hint, Diff ;

    string Name[101];


struct player
{
    char name[51];
    int point=0;
    int position=0;

};



void MainMenu();

 #include "hints.cpp";

 #include "game.cpp"

 #include "scoreboard.cpp";



int main()
{

    MainMenu();
    system("cls");
    cout<<endl<<endl<<"                   Thanks for Playing          "<<endl;
    return 0;

}

void MainMenu()
{
    system("cls");

    cout<<"\t\t\t\t\t***** Welcome To Idea test Game  ***** "<<endl<<endl;
    cout<<"\t\t\t\t\t----- Main Menu -----"<<endl<<endl<<endl;

    cout<<"\t\t1. View Last scores "<<endl;
    cout<<"\t\t2. Start game"<<endl;
    cout<<"\t\t3. Close App"<<endl<<endl<<endl;
    cout<<"Enter Your Choice"<<" : ";

    switch(getchar())
    {

    case '1':
        ScoreBord();
        break;
    case '2':
       Game();
        break;
    case '3':
        return ;
    default:
        MainMenu();
    }


}
