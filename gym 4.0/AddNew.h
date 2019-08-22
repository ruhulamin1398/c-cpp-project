
int CkId(int id )
{
    FILE *fp;
    struct Person a;
    fp=fopen("file.txt","ab+");
    fseek(fp,0,SEEK_SET);

    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(a.Id==id)
            return 0;
    }

    return 1;
}


void AddNew()
{
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
    while(CkId(P.Id)==0)
    {
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
