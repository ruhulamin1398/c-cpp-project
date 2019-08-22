void buy() {
    system("cls");

    cout<<"\t****** BUY TICKET ******"<<endl<<endl;
    cout<<"Note: Show time 6 PM only "<<endl;
    cout<<"Note: price 400 Taka "<<endl<<endl;


    cout<<"\t SELECT MOVIE :  "<<endl<<endl;
    FILE *fp;
    fp=fopen("movie.dat","ab+");
    struct movie m[101],temp;
    int i=0;
    fseek(fp,0,SEEK_SET);
    while(fread(&temp,sizeof(temp),1,fp)==1) {
        cout<<temp.id<<". "<<temp.moviename<<"("<<temp.date<<")"<<endl;
        i++;
        m[i].id=temp.id;
        strcpy(m[i].moviename,temp.moviename);
        strcpy(m[i].date,temp.date);
    }

    fclose(fp);
//////////////////////////////////

    struct ticket newticket;
    cout<<endl<<endl;
    cout<<"Enter Your Choice"<<" : ";
    int id;
    cin>>id;
    strcpy(newticket.date,m[id].date);
    strcpy(newticket.moviename,m[id].moviename);

    cout<<endl<<endl<<"------ You are selected "<<newticket.moviename<<" ----- "<<endl;
    cout<<"Enter Your Name : ";
    cin>>newticket.name;
    cout<<"Enter Your Phone : ";
    cin>>newticket.phone;
/////////////////////////////////////

    FILE *fp1;
    fp1=fopen("ticket.dat","ab+");
    struct ticket tempticket;
    fseek(fp1,0,SEEK_SET);
    int lastid=0;
    while(fread(&tempticket,sizeof(tempticket),1,fp1)==1) {
        lastid=tempticket.id;
    }
    newticket.id=lastid+1;
    fseek(fp1,0,SEEK_END);
    fwrite(&newticket,sizeof(newticket),1,fp1);
    fclose(fp1);
////////////////////////////
    cout<<endl<<"\t Congratulation you buy this ticket successfully"<<endl;
    cout<<endl<<"\t Your tickt id is "<<newticket.id<<endl;
    cout<<endl<<"1. Buy Again"<<endl;
    cout<<"2. Return Home Page"<<endl;
    cout<<"Enter Your Choice"<<" : ";
    int tmp;
    cin>>tmp;
    if(tmp==1)
        buy();
    else
        Home();

}


void reserved(){





    system("cls");
    FILE *fp;
    struct ticket temp;
    fp=fopen("ticket.dat","ab+");
    fseek(fp,0,SEEK_SET);


    while(fread(&temp,sizeof(temp),1,fp)==1)
    {
        cout<<"\t-----******--------"<<endl;
        cout<<"ID       : "<<temp.id<<endl;
        cout<<"Movie    : "<<temp.moviename<<endl;
        cout<<"Name     : "<<temp.name<<endl;
        cout<<"Phone    : "<<temp.phone<<endl;
        cout<<"Phone    : "<<temp.date<<endl;
        cout<<"Time     : "<<temp.time<<endl;

    }
    fclose(fp);

    cout<<endl<<endl;
cout<<endl<<endl<<"Press Any Key to Home Page"<<endl;
getchar();
getchar();

Home();

}

