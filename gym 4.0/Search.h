
void SearchId(){
        cout<<"\t\t\t\t\t----- Search By ID  -----"<<endl<<endl<<endl;

    FILE *fp;
    struct Person a;
    fp=fopen("file.txt","ab+");
        cout<<"Enter Id : ";
        int id;
        cin>>id;
        fseek(fp,0,SEEK_SET);
        int ind=0;

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(id==a.Id)
            {
                cout<<"\t-----******--------"<<endl;
                cout<<"ID       : "<<a.Id<<endl;
                cout<<"Catagory : "<<a.Catagory<<endl;
                cout<<"Name     : "<<a.Name<<endl;
                cout<<"Address  : "<<a.Address<<endl;
                cout<<"Contact  : "<<a.Contact<<endl;
                ind=1;
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

void SearchName(){
            cout<<"\t\t\t\t\t----- Search By Name  -----"<<endl<<endl<<endl;

    FILE *fp;
    struct Person a;
    fp=fopen("file.txt","ab+");
        cout<<"Enter Name : ";
        char name[101];
        cin>>name;
        fseek(fp,0,SEEK_SET);
        int ind=0;

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.Name,name)==0)
            {
                cout<<"\t-----******--------"<<endl;
                cout<<"ID       : "<<a.Id<<endl;
                cout<<"Catagory : "<<a.Catagory<<endl;
                cout<<"Name     : "<<a.Name<<endl;
                cout<<"Address  : "<<a.Address<<endl;
                cout<<"Contact  : "<<a.Contact<<endl;
                cout<<"\t-----******--------"<<endl;
                ind=1;

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

void SearchCategory(){
            cout<<"\t\t\t\t\t----- Search By Name  -----"<<endl<<endl<<endl;

    FILE *fp;
    struct Person a;
    fp=fopen("file.txt","ab+");
        cout<<"Enter Category : ";
        char category[101];
        cin>>category;
        fseek(fp,0,SEEK_SET);
        int ind=0;

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.Catagory,category)==0)
            {
                cout<<"\t-----******--------"<<endl;
                cout<<"ID       : "<<a.Id<<endl;
                cout<<"Category : "<<a.Catagory<<endl;
                cout<<"Name     : "<<a.Name<<endl;
                cout<<"Address  : "<<a.Address<<endl;
                cout<<"Contact  : "<<a.Contact<<endl;
                cout<<"\t-----******--------"<<endl;
                ind=1;

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

void SearchAddress(){
            cout<<"\t\t\t\t\t----- Search By Address  -----"<<endl<<endl<<endl;

    FILE *fp;
    struct Person a;
    fp=fopen("file.txt","ab+");
        cout<<"Enter Address : ";
        char address[101];
        cin>>address;
        fseek(fp,0,SEEK_SET);
        int ind=0;

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.Address,address)==0)
            {
                cout<<"\t-----******--------"<<endl;
                cout<<"ID       : "<<a.Id<<endl;
                cout<<"Catagory : "<<a.Catagory<<endl;
                cout<<"Name     : "<<a.Name<<endl;
                cout<<"Address  : "<<a.Address<<endl;
                cout<<"Contact  : "<<a.Contact<<endl;
                cout<<"\t-----******--------"<<endl;
                ind=1;

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

void SearchContact(){
            cout<<"\t\t\t\t\t----- Search By ID  -----"<<endl<<endl<<endl;

    FILE *fp;
    struct Person a;
    fp=fopen("file.txt","ab+");
        cout<<"Enter contact : ";
        char contact[101];
        cin>>contact;
        fseek(fp,0,SEEK_SET);
        int ind=0;

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.Contact,contact)==0)
            {
                cout<<"\t-----******--------"<<endl;
                cout<<"ID       : "<<a.Id<<endl;
                cout<<"Catagory : "<<a.Catagory<<endl;
                cout<<"Name     : "<<a.Name<<endl;
                cout<<"Address  : "<<a.Address<<endl;
                cout<<"Contact  : "<<a.Contact<<endl;
                cout<<"\t-----******--------"<<endl;
                ind=1;

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

void Search()
{
        system("cls");
    cout<<"\t\t\t\t\t----- Search Menu -----"<<endl<<endl<<endl;

    cout<<"\t\t1. Search by Id "<<endl;
    cout<<"\t\t2. Search by Name"<<endl;
    cout<<"\t\t3. Search by Category"<<endl;
    cout<<"\t\t4. Search by Address"<<endl;
    cout<<"\t\t5. Search by Contact"<<endl;
    cout<<"\t\t6. HomePage"<<endl<<endl<<endl;
    cout<<"Enter Your Choice"<<" : ";

     switch(getchar())
    {
    case '1':
        SearchId();
        break;
    case '2':
        SearchName();
        break;
    case '3':
        SearchCategory();
        break;
    case '4':
        SearchAddress();
    case '5':
        SearchContact();
    case '6':
           HomePage();
    default:
        Search();
    }


}
