void Sell() {

    total =0 ;
    cart.clear();
    welcome();

    string barcode;

    cout<<"Barcode (Type 'F' to finish): ";
    while( cin>>barcode and barcode !="f" and barcode !="F" ) {
        it = item.find(barcode);
        if( it!= item.end()) {
            total +=it->second.second;
            cart[barcode]++;
            Receipt();

        } else
            cout<<"\t Wrong !!! Product Doesn't Exist .. Try Again"<<endl;
        cout<<endl<<"Barcode (Type 'F' to finish): ";
    }



    Payment();





}



void Receipt() {


    system("cls");
    welcome();
    gotoxy(1,12);
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Product List \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    gotoxy(0,14);
    int linen=95;
    while(linen--)
        printf("-");

    gotoxy(1,15);
    printf("| Item");
    gotoxy(30,15);
    printf("| Barcode");
    gotoxy(45,15);
    printf("|  Price");
    gotoxy(60,15);
    printf("| Quantity ");
    gotoxy(75,15);
    printf("| Total");
    gotoxy(94,15);
    printf("|");

    gotoxy(0,16);

    linen=95;
    while(linen--)
        printf("-");

    int j =17;
    itr=cart.begin();
    for(int i = 0 ; i<cart.size() ; i++) {
        it= item.find(itr->first);

        gotoxy(1,j);
        cout<<"|  "<<it->second.first;
        gotoxy(30,j);
        cout<<"|  "<<it->first;
        gotoxy(45,j);
        cout<<"|  "<<it->second.second;
        gotoxy(60,j);
        cout<<"|"<<itr->second;
        gotoxy(75,j);
        cout<<"|  "<<it->second.second*itr->second;
        gotoxy(94,j);
        cout<<"|"<<endl;
        j+=2;

        gotoxy(0,j-1);
        linen=95;
        while(linen--)
            printf("-");
itr++;
    }

    gotoxy(40,j);
    cout<<"|  "<<"Total";
    gotoxy(65,j);
    cout<<"|  "<<total;
    gotoxy(94,j);
    cout<<"|"<<endl;
    j+=2;

    gotoxy(40,j-1);
    linen=95-40;
    while(linen--)
        printf("-");

    return ;

}


void Payment() {
    welcome();
    Receipt();
    int pay=0 ;
    int p;

    while(pay<total  ) {
        cout<<endl<< "Cash received: " ;
        cin>>p;
        pay+=p;
        if( pay<total)
        cout<<"[!] More cash needed: "<<total-pay<<endl;

    }
    cout<<"Change Given: "<<pay-total<<endl;
    cout<<endl;
            cout<<"Try another search?(Y/N): ";
            getchar();
            char ch=getchar();

        if(ch=='y' or ch=='Y')
           Sell();
        else
            HomePage();




}
