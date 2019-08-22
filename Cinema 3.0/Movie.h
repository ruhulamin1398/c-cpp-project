
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
    cout<<endl<<endl<<"Press Any Key to Hompe Page"<<endl;
    getchar();
    getchar();

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

    cout<<"Enter Movie id  : ";
    int id ;
    cin>>id;


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

    for(int j=0  ; j<=i ; j++) {

        if( m[j].id !=id) {
            fwrite(&m[j],sizeof(m[j]),1,fp1);
        }
    }
    fclose(fp1);
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
