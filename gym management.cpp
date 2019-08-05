#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

struct Person {
    int Id;
    char Catagory[101];
    char Name[101];
    char Address[101];
    char Contact[101];
};

int temp;
void HomePage();
void View();
void Remove();
void Search();
void AddNew();
int CkId(int id );

int main() {
    string password="1234";
    cout<<"\t\t\t\t\t\tWelcome to GYM Management System"<<endl;
    cout<<"Enter Your PassWord"<<" : ";
    string pass;
    cin>>pass;
    while(pass!=password) {
        cout<<"\t\t\t\tIncorrect Password!!!!"<<endl<<"\t\t\t\tTry Again"<<" : "<<endl;
        cin>>pass;
    }
    HomePage();
    return 0 ;
}

void HomePage() {
    system("cls");
    cout<<"\t\t\t\t\t----- Main Menu -----"<<endl<<endl<<endl;
    cout<<"\t\t1. Add new Trainer/Member"<<endl;
    cout<<"\t\t2. View Trainer/Member"<<endl;
    cout<<"\t\t3. Search Trainer/Member"<<endl;
    cout<<"\t\t4. Remove TrainerMember"<<endl;
    cout<<"\t\t5. Close App"<<endl<<endl<<endl;
    cout<<"Enter Your Choice"<<" : ";
    switch(getchar()) {
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

int CkId(int id ) {
    FILE *fp;
    struct Person a;
    fp=fopen("file.txt","ab+");
    fseek(fp,0,SEEK_SET);
    while(fread(&a,sizeof(a),1,fp)==1) {
        if(a.Id==id)
            return 0;
    }
    return 1;
}

void AddNew() {
    system("cls");
    cout<<"\t\t\t\t\t----- Add New -----"<<endl<<endl<<endl;
    cout<<"\t\t 1. Add new Trainer"<<endl;
    cout<<"\t\t 2. Add new Member"<<endl;
    cout<<"Enter Your Choice"<<" : ";
    struct Person P;
    int Cat;
    cin>>Cat;
    if(Cat==1)
        strcpy(P.Catagory,"Trainer");
    else if(Cat==2)
        strcpy(P.Catagory,"Member");
    else
        AddNew();
    system("cls");
    cout<<"\t\t Add New "<<P.Catagory<<endl<<endl;
    cout<<"Id      :";
    cin>>P.Id;
    while(CkId(P.Id)==0) {
        cout<<" Warning !!! This Id is Exist"<<endl<<"Enter Again"<<endl;
        cout<<"Id      : ";
        cin>>P.Id;
    }
    cout<<"Name    : ";
    cin>>P.Name;
    cout<<"Address : ";
    cin>>P.Address;
    cout<<"Contact : ";
    cin>>P.Contact;

    FILE *fp;
    fp=fopen("file.txt","ab+");
    fseek(fp,0,SEEK_END);
    fwrite(&P,sizeof(P),1,fp);
    fclose(fp);

    cout<<endl<<"\t1. Add Again"<<endl;
    cout<<"\t2. Return Home Page"<<endl;
    cout<<"Enter Your Choice"<<" : ";
    cin>>temp;
    if(temp==1)
        AddNew();
    else
        HomePage();
}
void View() {
    system("cls");
    FILE *fp;
    struct Person a;
    fp=fopen("file.txt","ab+");
    fseek(fp,0,SEEK_SET);
    while(fread(&a,sizeof(a),1,fp)==1) {
        cout<<"\t-----******--------"<<endl;
        cout<<"ID       : "<<a.Id<<endl;
        cout<<"Catagory : "<<a.Catagory<<endl;
        cout<<"Name     : "<<a.Name<<endl;
        cout<<"Address  : "<<a.Address<<endl;
        cout<<"Contact  : "<<a.Contact<<endl;
    }
    fclose(fp);
    cout<<"Enter to go Homepage  : "<<endl;
    getchar();
    getchar();
    HomePage();
}

void Remove() {
    system("cls");
    cout<<"\t\t\t\t\t----- REMOVE -----"<<endl<<endl<<endl;
    cout<<"\t Enter Id : ";
    int id;
    cin>>id;
    struct Person a;
    FILE *fp;
    fp=fopen("file.txt","ab+");
    fseek(fp,0,SEEK_SET);
    int ind=0 ;
    while(fread(&a,sizeof(a),1,fp)==1) {
        if(id==a.Id) {
            ind=1;
            break;
        }
    }
    if(ind==0) {
        system("cls");
        cout<<"\t\t Not Found !!!!!!   "<<endl<<endl;;

        cout<<"\t1. Try again"<<endl;
        cout<<"\t2. Return Home Page"<<endl;
        cout<<"Enter Your Choice"<<" : ";
        cin>>temp;
        if(temp==1)
            Remove();
        else
            HomePage();
    } else {
        cout<<" Name : "<<a.Name<<endl;
        cout<<"\tSure Want To Delete"<<endl;
        cout<<endl<<"\t1. Yes"<<endl;
        cout<<endl<<"\t2. No And try again"<<endl;
        cout<<endl<<"\t3. Return Home Page"<<endl;
        cout<<"Enter Your Choice"<<" : ";
        cin>>temp;
        if(temp==1) {
            FILE *fp;
            fp=fopen("file.txt","ab+");
            fseek(fp,0,SEEK_SET);
            struct Person m[101],temp;
            fseek(fp,0,SEEK_SET);
            int i=-1;
            while(fread(&temp,sizeof(temp),1,fp)==1) {
                i++;
                m[i].Id=temp.Id;
                strcpy(m[i].Catagory,temp.Catagory);
                strcpy(m[i].Name,temp.Name);
                strcpy(m[i].Address,temp.Address);
                strcpy(m[i].Contact,temp.Contact);
            }
            fclose(fp);
            //////////////////////////////
            FILE *fp1;
            fp1=fopen("file.txt","w+");
            fseek(fp1,0,SEEK_SET);

            for(int j=0  ; j<=i ; j++) {

                if( m[j].Id !=id) {
                    fwrite(&m[j],sizeof(m[j]),1,fp1);
                }
            }
            fclose(fp1);
            cout<<"Successfully Deleted "<<endl;
            cout<<"Enter to go Homepage  : "<<endl;
            getchar();
            getchar();
            HomePage();
        }

        else if(temp==2)
            Remove();
        else
            HomePage();
    }
}

void Search() {
    cout<<"\t\t\t\t\t----- Search -----"<<endl<<endl<<endl;
    FILE *fp;
    struct Person a;
    fp=fopen("file.txt","ab+");
    cout<<"Enter Id : ";
    int id;
    cin>>id;
    fseek(fp,0,SEEK_SET);
    int ind=0;

    while(fread(&a,sizeof(a),1,fp)==1) {
        if(id==a.Id) {
            cout<<"\t-----******--------"<<endl;
            cout<<"ID       : "<<a.Id<<endl;
            cout<<"Catagory : "<<a.Catagory<<endl;
            cout<<"Name     : "<<a.Name<<endl;
            cout<<"Address  : "<<a.Address<<endl;
            cout<<"Contact  : "<<a.Contact<<endl;
            cout<<"\t-----******--------"<<endl;
            ind=1;
            break;
        }
    }
    if(ind==0 )
        cout<<" \t\tData Not Found  !!!!!!"<<endl<<endl;
    cout<<"\t1. Search Again"<<endl;
    cout<<endl<<"\t2. Return Home Page"<<endl;
    cout<<"Enter Your Choice"<<" : ";
    cin>>temp;
    if(temp==1)
        Search();
    else
        HomePage();
}

