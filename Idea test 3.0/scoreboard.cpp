void ScoreBord()
{

    system("cls");

    cout<<"\t\t\t\t\t----- Score Board -----"<<endl<<endl<<endl;
    FILE *fp;
    struct player temp;
    fp=fopen("player.txt","ab+");
    fseek(fp,0,SEEK_SET);


    while(fread(&temp,sizeof(temp),1,fp)==1)
    {
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
