
void View() {
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
    gotoxy(40,15);
    printf("| Barcode");
    gotoxy(65,15);
    printf("| Price");
    gotoxy(94,15);
    printf("|");

    gotoxy(0,16);

    linen=95;
    while(linen--)
        printf("-");





    int j =17;

    for(it=item.begin() ; it!=item.end() ; it++) {
        j++;
        gotoxy(1,j);
        cout<<"|  "<<it->second.first;
        gotoxy(40,j);
        cout<<"|  "<<it->first;
        gotoxy(65,j);
        cout<<"|  "<<it->second.second;
        gotoxy(94,j);
        cout<<"|"<<endl;
        j+=2;

        gotoxy(0,j-1);
        linen=95;
        while(linen--)
            printf("-");

    }


    cout<<endl<<endl<<endl;
    cout<<"Press Any Key to go Home "<<endl;
    getchar();
    getchar();
    HomePage();

}
