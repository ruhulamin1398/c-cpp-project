#include<bits/stdc++.h>
using namespace std;

struct player {
    char name[51];
    int point=0;
    int position=0;

};

void MainMenu();
void ScoreBord();
void hint(int n, int MaxInput, int MinInput,int Diff );
void Game();


int main() {
    MainMenu();
    system("cls");
    cout<<endl<<endl<<"                   Thanks for Playing          "<<endl;
    return 0;
}

void MainMenu() {
    system("cls");
    cout<<"\t\t\t\t\t***** Welcome To Idea test Game  ***** "<<endl<<endl;
    cout<<"\t\t\t\t\t----- Main Menu -----"<<endl<<endl<<endl;

    cout<<"\t\t1. View Last scores "<<endl;
    cout<<"\t\t2. Start game"<<endl;
    cout<<"\t\t3. Close App"<<endl<<endl<<endl;
    cout<<"Enter Your Choice"<<" : ";

    switch(getchar()) {

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


void ScoreBord() {
    system("cls");
    cout<<"\t\t\t\t\t----- Score Board -----"<<endl<<endl<<endl;
    FILE *fp;
    struct player temp;
    fp=fopen("player.txt","ab+");
    fseek(fp,0,SEEK_SET);

    while(fread(&temp,sizeof(temp),1,fp)==1) {
        if(temp.position==1)
            cout<<"\t-----******--------"<<endl;
        cout<<"Position : "<<temp.position<<" "<<temp.name<<"("<<temp.point<<")"<<endl;
    }
    fclose(fp);

    cout<<endl<<endl;
    cout<<endl<<endl<<"Press Any Key to Main Menu"<<endl;
    getchar();
    getchar();
    MainMenu();
}

void Game() {
    system("cls");
    int n,i, TotalPlayer, LuckyNumber, MembersPoint[101],MaxInput, MinInput,  MembersInput[101], TotalRound,Hint ;
    string Name[101];
    cout<<"\t\t\t **** Welcome To the Game **** "<<endl;
    cout<<"Enter total Player Number:    ";
    cin>>TotalPlayer;
    for( i=0 ; i<TotalPlayer ; i++) {
        cout<<"Enter the nickname  of player number  "<<i+1<<"  : ";
        cin>>Name[i];
        MembersPoint[i]=0;
    }
    cout<<"Enter Guess number : "<<endl;
    cout<<"Lowest number : ";
    cin>>MinInput;
    cout<<"highest number : ";
    cin>>MaxInput;
    cout<<"Total Round want to play = " ;
    cin>>TotalRound;

    cout<<"             Want to Hints !!!!!!!!!!! " <<endl<<"Enter 1 for Hints or Enter any number if doesn't  need to hints "<<endl ;
    cin>>Hint;

    for(int j=0 ; j<TotalRound; j++) {
        system("cls");
        cout<<"\t\t\t\t\t----- Score Board -----"<<endl<<endl<<endl;
        for( i=0 ; i<TotalPlayer ; i++)
            cout<<Name[i] <<" : "<<MembersPoint[i]<<endl;
        cout<<endl<<endl;

        cout<<endl<<endl<<"------ ROUND "<< j+1<<"------"<<endl<<endl;

        int Diff= MaxInput-MinInput+1;
        LuckyNumber= (rand()%Diff)+MinInput;
        if(Hint==1)
            hint(LuckyNumber,MinInput,MaxInput,Diff);

        for( i=0 ; i<TotalPlayer ; i++) {
            cout<<Name[i]<<"'s Turn"<<" :  " << "Enter guess number Between " <<MinInput<<"  - "<< MaxInput<<"  : " ;
            cin>>MembersInput[i];
            if(MembersInput[i] >MaxInput and  MembersInput[i]<MinInput) {
                cout<<endl<<"       Worng !!!!!"<< endl<<"     Please input again       " << endl;
                i--;
            }
        }

        cout<<endl<<" Number is "<<LuckyNumber<<endl;
        for( i=0 ; i<TotalPlayer ; i++) {
            if(MembersInput[i]==LuckyNumber) {
                MembersPoint[i]++;
                cout<<"Congratulation "<<Name[i]<<" : Your score is updated, Now your point is :"<<MembersPoint[i]<<endl;
            } else
                cout<<"Sorry "<<Name[i]<<" : Your score is Not updated, Now your point is :"<<MembersPoint[i]<<endl;
        }
        cout<<"Enter to continue........."<<endl;
        getchar();
        getchar();
    }

    ///                               *****   Calculating Result *******
    for(int  i=0 ; i<TotalPlayer ; i++) {
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

    for( i=0 ; i<TotalPlayer ; i++)
        cout<< "Position "<<i+1<<" "<< Name[i] << ": Your Point is "<<MembersPoint[i]<<endl;
    cout<<endl<<endl<<endl;

    ///                                                             *****   Saving Result *******
    struct player p1;

    FILE *fp;
    fp=fopen("player.txt","ab+");

    for( i=0 ; i<TotalPlayer ; i++) {
        strcpy(p1.name, Name[i].c_str());

        p1.position =i+1;
        p1.point= MembersPoint[i];

        fseek(fp,0,SEEK_END);
        fwrite(&p1,sizeof(p1),1,fp);
    }
    fclose(fp);
///                                                       ****** End ****************************
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

void hint(int n, int MaxInput, int MinInput,int Diff ) {
    int t=0;
    cout <<endl<<endl;
    cout<<"\t\t\t\t\t ##### Hints #####"<<endl;
    int m= sqrt(n);
    int flag=0 ;
    for(int i = 2; i <= m; i++) {
        if(n % i == 0) {
            flag=1;
            break;
        }
    }
    if (flag==0) {
        t++;
        cout << "\t\t\t"<<t<<". Number is Prime."<<endl;
    } else {
        t++;
        if( n%2==0)
            cout << "\t\t\t"<<t<<". Number is Even."<<endl;
        else
            cout << "\t\t\t"<<t<<". Number is Odd."<<endl;
        t++;
        if( n%3==0)
            cout << "\t\t\t"<<t<<". Number is Divided By 3."<<endl;
        else
            cout << "\t\t\t"<<t<<". Number isn't Divided by 3."<<endl;
        t++;
        if( n%5==0)
            cout << "\t\t\t"<<t<<". Number is Divided By 5."<<endl;
        else
            cout << "\t\t\t"<<t<<". Number isn't Divided by 5."<<endl;
    }
    t++;
    if(n>( MinInput+MaxInput)/2)

        cout << "\t\t\t"<<t<<". Number is situated in last half."<<endl;
    else
        cout << "\t\t\t"<<t<<". Number is situated in first half."<<endl;

    return ;
}

