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
void hint(int n, int MaxInput, int MinInput,int Diff );
void  CurrentScore();
void   GenerateNumber(int i);
void Game();
void ScoreBord();




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




void hint(int n, int MaxInput, int MinInput,int Diff )
{


    cout <<endl<<endl;
    cout<<"\t\t\t\t\t ##### Hints #####"<<endl;

    int flag=0 ;

    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            flag=1;
            break;
        }
    }

    if (flag==0)
    {

        cout << "\t\t\t"<<"* "<<". Number is Prime."<<endl;

    }
    else
    {

        if( n%2==0)
        {

            cout << "\t\t\t"<<"* "<<". Number is Even."<<endl;

        }
        else
        {
            cout << "\t\t\t"<<"* "<<". Number is Odd."<<endl;

        }

        if( n%3==0)
        {

            cout << "\t\t\t"<<"* "<<". Number is Divided By 3."<<endl;

        }
        else
        {
            cout << "\t\t\t"<<"* "<<". Number doesn't Divided by 3."<<endl;
        }

        if( n%5==0)
        {
            cout << "\t\t\t"<<"* "<<". Number is Divided By 5."<<endl;

        }
        else
        {
            cout << "\t\t\t"<<"* "<<". Number doesn't Divided by 5."<<endl;

        }

    }

    if(n>( MinInput+MaxInput)/2)

        cout << "\t\t\t"<<"* "<<". Number is situated in last half."<<endl;
    else
        cout << "\t\t\t"<<"* "<<". Number is situated in first half."<<endl;

    return ;
}


void  CurrentScore() {
    cout<<"\t\t\t\t\t----- Score Board -----"<<endl<<endl<<endl;
    for( int i=0 ; i<TotalPlayer ; i++) {
        cout<<Name[i] <<" : "<<MembersPoint[i]<<endl;
    }
    cout<<endl<<endl;
}




void   GenerateNumber(int i) {
    system("cls");
    CurrentScore();
    cout<<"\t\t****Lucky  Number Generated Successfully****"<<endl;
    LuckyNumber=MinInput + (rand()%Diff);
    hint(LuckyNumber,MinInput,MaxInput,Diff);
    cout<<endl<<endl<<"------ ROUND "<< i+1<<"------"<<endl<<endl;

}



void Game() {
    system("cls");

    cout<<"\t\t\t **** Welcome To the Game **** "<<endl;

    cout<<"Enter total Player Number:    ";
    cin>>TotalPlayer;
    while(TotalPlayer<2) {
        cout<<"\t\t\t Wrong input !!!!"<<endl<<"Player number must be at least 2"<<endl;
        cout<<"Enter total Player Number:    ";
        cin>>TotalPlayer;
    }
    for( i=0 ; i<TotalPlayer ; i++) {
        cout<<"Enter the nickname  of player number  "<<i+1<<"  : ";
        cin>>Name[i];
        MembersPoint[i]=0;
    }
    cout<<"Enter Guess number : "<<endl;
    cout<<"Lowest number : ";
    cin>>MinInput;
    cout<<"Highest number : ";
    cin>>MaxInput;
    while(MaxInput==MinInput) {
        cout<<"\t\t\t Wrong input !!!!"<<endl<<"Highest number and Lowest number should not be equal"<<endl;
        cout<<"Enter Guess number : "<<endl;
        cout<<"Lowest number : ";
        cin>>MinInput;
        cout<<"highest number : ";
        cin>>MaxInput;
    }
    if(MaxInput<MinInput) {
        int temp = MaxInput;
        MaxInput=MinInput;
        MinInput=temp;
    }

    Diff= MaxInput-MinInput+1;

    cout<<"Total Round want to play = " ;
    cin>>TotalRound;
    while (TotalRound<=0) {
        cout<<"\t\t\t Wrong input !!!!"<<endl<<"Total Round must be at least 1"<<endl;
        cout<<"Total Round want to play = " ;
        cin>>TotalRound;

    }




    GenerateNumber(0);

    for(int j=0 ; j<TotalRound; j++)  {

        if(j!=0)
            cout<<endl<<endl<<"------ ROUND "<< j+1<<"------"<<endl<<endl;



        for( i=0 ; i<TotalPlayer ; i++) {
            cout<<Name[i]<<"'s Turn"<<" :  " << "Enter guess number Between " <<MinInput<<"  - "<< MaxInput<<"  : " ;
            cin>>MembersInput;
            while(MembersInput >MaxInput ||  MembersInput<MinInput) {
                cout<<endl<<"       Worng !!!!!"<< endl<<"     Please input again       " << endl;
                cout<<Name[i]<<"'s Turn"<<" :  " << "Enter guess number Between " <<MinInput<<"  - "<< MaxInput<<"  : " ;
                cin>>MembersInput;

            }

            if(MembersInput==LuckyNumber) {
                MembersPoint[i]++;
                cout<<"Congratulation "<<Name[i]<<" : Your Guess the Right Number, Now your point is :"<<MembersPoint[i]<<endl;
                cout<<"Enter to continue........."<<endl;
                getchar();
                getchar();
                GenerateNumber(j);
            }



            else if(LuckyNumber>MembersInput)
                cout<<"Number is bigger then "<<MembersInput<<endl;
            else
                cout<<"Number is smaller then "<<MembersInput<<endl;
        }

        cout<<"Enter to continue........."<<endl;
        getchar();
        getchar();
    }





    ///                               *****   Calculating Result *******




    for(int  i=0 ; i<TotalPlayer ; i++)

    {
        for( int j=0 ; j<TotalPlayer-1 ; j++) {
            if(MembersPoint[i] >MembersPoint[j]) {
                int Temp=MembersPoint[i];
                MembersPoint[i]=MembersPoint[j];
                MembersPoint[j]=Temp;
                string TEMP=Name[i];
                Name[i]=Name[j];
                Name[j]=TEMP;
            }
        }
    }



    ///                  *****   Printing Result *******

    system("cls");

    cout<<endl<<endl<<endl<<"   *****   After "<<TotalRound<<" Round   *****  "<<endl;
    cout<<"            Result is "         <<endl<<endl<<endl<<endl;

    for( i=0 ; i<TotalPlayer ; i++) {
        cout<< "Position "<<i+1<<" "<< Name[i] << ": Your Point is "<<MembersPoint[i]<<endl;
    }

    cout<<endl<<endl<<endl;

    ///                                     *****   Saving Result *******


    FILE *fp;
    fp=fopen("player.txt","ab+");

    for( i=0 ; i<TotalPlayer ; i++) {

        struct player p1;

        strcpy(p1.name, Name[i].c_str());

        p1.position =i+1;
        p1.point= MembersPoint[i];

        fseek(fp,0,SEEK_END);
        fwrite(&p1,sizeof(p1),1,fp);

    }

    fclose(fp);
///                                      ****** End ******
    cout<<endl<<"1. Play Again"<<endl;
    cout<<"2. Return Home Page"<<endl;
    cout<<"Enter Your Choice"<<" : ";
    int tmp;
    cin>>tmp;
    if(tmp==1)
        Game();
    else
        MainMenu();

    return ;

}
void ScoreBord()
{

    system("cls");

    cout<<"\t\t\t\t\t----- Score Board -----"<<endl<<endl<<endl;

    FILE *fp;
    struct player p1;
    fp=fopen("player.txt","ab+");
    fseek(fp,0,SEEK_SET);

    while(fread(&p1,sizeof(p1),1,fp)==1)
    {
        if(p1.position==1)
        cout<<"\t-----******--------"<<endl;
        cout<<"Position : "<<p1.position<<" "<<p1.name<<"("<<p1.point<<")"<<endl;
    }
    fclose(fp);

cout<<endl<<endl;
cout<<endl<<endl<<"Press Any Key to Main Menu"<<endl;
getchar();
getchar();
        MainMenu();
}


