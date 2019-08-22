void View()
{
    system("cls");
    FILE *fp;
    struct Person a;
    fp=fopen("file.txt","ab+");
    fseek(fp,0,SEEK_SET);

    while(fread(&a,sizeof(a),1,fp)==1)
    {
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
