#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
struct ticket{

    char name[101] ;
    int id=0;
    char phone[101] ;
   char moviename[101];
    char time[101]="6 PM";
    int price=400;
    char date[101];
};
struct movie{
    int id=0;
    char moviename[101];
    char date[101];
};



void Home();
void buy();
void reserved();
int VerifyName(char name[101]);
void movies();
void addmovie();
void  removemovie();






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
    cout<<endl<<endl<<"Enter any Integer to Home Page"<<endl;
    int tmp;
    cin>>tmp;

Home();

}

int VerifyName(char name[101]) {

    FILE *fp;
    fp=fopen("movie.dat","ab+");

    struct movie temp;
    fseek(fp,0,SEEK_SET);
    while(fread(&temp,sizeof(temp),1,fp)==1) {
        if( strcmp(temp.moviename,name)==0 )
            return 1;

    }
    return 0 ;


}

void movies() {


    system("cls");
    cout<<"\t****** MOVIE LIST ******"<<endl<<endl;



    FILE *fp;
    fp=fopen("movie.dat","ab+");

    struct movie temp;
    fseek(fp,0,SEEK_SET);

    while(fread(&temp,sizeof(temp),1,fp)==1) {
        cout<<temp.id<<". "<<temp.moviename<<"("<<temp.date<<")"<<endl;
    }

    fclose(fp);

    cout<<endl<<endl;
    cout<<endl<<endl<<"Enter any Integer to Home Page"<<endl;
    int tmp;
    cin>>tmp;
    Home();
}

//////////////////////////////////////////////////////////////////////////


void addmovie() {

    system("cls");
    cout<<"\t****** Add new movie ******"<<endl<<endl;

    FILE *fp;
    fp=fopen("movie.dat","ab+");

    struct movie temp,newmovie;
    fseek(fp,0,SEEK_SET);
    int lastid=0;
    while(fread(&temp,sizeof(temp),1,fp)==1) {
        lastid=temp.id;

    }
    newmovie.id=lastid+1;

    getchar();
    cout<<"Enter new movie name : ";
    cin.getline (newmovie.moviename,101);

    while (VerifyName(newmovie.moviename)==1) {
        cout<<"\t\t Movie already exist"<<endl;
        cout<<"Enter new movie name : ";
        cin.getline (newmovie.moviename,101);


    }
    cout<<"Enter Date : ";
    cin.getline (newmovie.date,101);



    fseek(fp,0,SEEK_END);
    fwrite(&newmovie,sizeof(newmovie),1,fp);
    fclose(fp);
    cout<<endl<<"\t Congratulation you Add movie successfully"<<endl;
    cout<<endl<<"1. Add Again"<<endl;
    cout<<"2. Return Home Page"<<endl;
    cout<<"Enter Your Choice"<<" : ";
    int tmp;
    cin>>tmp;
    if(tmp==1)
        addmovie();
    else
        Home();


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void  removemovie() {

    system("cls");
    cout<<"\t****** Remove Movie******"<<endl<<endl;

    cout<<"Enter Movie Name  : ";
    char name[10];
    cin>>name;


    FILE *fp;
    fp=fopen("movie.dat","ab+");

    struct movie m[101],temp;
    fseek(fp,0,SEEK_SET);

    int i=-1;
    while(fread(&temp,sizeof(temp),1,fp)==1) {
        i++;
        m[i].id=temp.id;
        strcpy(m[i].moviename,temp.moviename);
        strcpy(m[i].date,temp.date);

    }
    fclose(fp);



    FILE *fp1;
    fp1=fopen("movie.dat","w+");
    fseek(fp1,0,SEEK_SET);
    int ind=0 ;
    for(int j=0  ; j<=i ; j++) {

        if( strcmp(m[j].moviename,name)!=0 ) {
            fwrite(&m[j],sizeof(m[j]),1,fp1);
        } else ind=1;
    }
    fclose(fp1);
    if (ind==1)
        cout<<endl<<"\t Congratulation you Remove movie successfully"<<endl;
    else
        cout<<"\t Movie not found"<<endl;
    cout<<endl<<"1. Add Again"<<endl;
    cout<<"2. Return Home Page"<<endl;
    cout<<"Enter Your Choice"<<" : ";
    int tmp;
    cin>>tmp;
    if(tmp==1)
        addmovie();
    else
        Home();

}
