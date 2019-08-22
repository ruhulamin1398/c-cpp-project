void  CurrentScore() {
    cout<<"\t\t\t\t\t----- Score Board -----"<<endl<<endl<<endl;
    for( int i=0 ; i<TotalPlayer ; i++) {
        cout<<Name[i] <<" : "<<MembersPoint[i]<<endl;
    }
    cout<<endl<<endl;
}




int   GenerateNumber() {
    system("cls");
    CurrentScore();
    cout<<"\t\t****Lucky  Number Generated Successfully****"<<endl;

    LuckyNumber= (rand()%Diff)+MinInput;

    hint(LuckyNumber,MinInput,MaxInput,Diff);
    return LuckyNumber;

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
    cout<<"highest number : ";
    cin>>MaxInput;
    while(MaxInput<=MinInput) {
        cout<<"\t\t\t Wrong input !!!!"<<endl<<"highest number should be bigger Lowest number"<<endl;
        cout<<"Enter Guess number : "<<endl;
        cout<<"Lowest number : ";
        cin>>MinInput;
        cout<<"highest number : ";
        cin>>MaxInput;
    }
    cout<<"Total Round want to play = " ;
    cin>>TotalRound;
    while (TotalRound<=0) {

        cout<<"\t\t\t Wrong input !!!!"<<endl<<"Total Round must be at least 1"<<endl;
        cout<<"Total Round want to play = " ;
        cin>>TotalRound;

    }

    Diff= MaxInput-MinInput+1;


    cout<<endl<<endl<<"------ ROUND "<< 1<<"------"<<endl<<endl;
    GenerateNumber();

    for(int j=0 ; j<TotalRound; j++)  {

        if(j!=0)
            cout<<endl<<endl<<"------ ROUND "<< j+1<<"------"<<endl<<endl;


        for( i=0 ; i<TotalPlayer ; i++) {
            cout<<Name[i]<<"'s Turn"<<" :  " << "Enter guess number Between " <<MinInput<<"  - "<< MaxInput<<"  : " ;
            cin>>MembersInput;
            while(MembersInput >MaxInput and  MembersInput<MinInput) {
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
                GenerateNumber();
            } else if(LuckyNumber>MembersInput)
                cout<<"Number is bigger then "<<MembersInput<<endl;
            else
                cout<<"Number is smaller then "<<MembersInput<<endl;
        }
//
//        cout<<endl<<" Number is "<<LuckyNumber<<endl;
//        for( i=0 ; i<TotalPlayer ; i++) {
//            if(MembersInput[i]==LuckyNumber) {
//                MembersPoint[i]++;
//                cout<<"Congratulation "<<Name[i]<<" : Your score is updated, Now your point is :"<<MembersPoint[i]<<endl;
//            } else
//                cout<<"Sorry "<<Name[i]<<" : Your score is Not updated, Now your point is :"<<MembersPoint[i]<<endl;
//        }
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
