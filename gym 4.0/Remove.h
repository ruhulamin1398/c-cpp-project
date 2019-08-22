
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


