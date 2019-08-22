
void hint(int n, int MaxInput, int MinInput,int Diff )
{

    int t=0;
    cout <<endl<<endl;
    cout<<"\t\t\t\t\t ##### Hints #####"<<endl;
    int m= sqrt(n);
    int flag=0 ;
    for(int i = 2; i <= m; i++)
    {
        if(n % i == 0)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
               t++;
        cout << "\t\t\t"<<t<<". Number is Prime."<<endl;

    }
    else
    {
            t++;
        if( n%2==0)
        {

            cout << "\t\t\t"<<t<<". Number is Even."<<endl;

        }
        else
        {
            cout << "\t\t\t"<<t<<". Number is Odd."<<endl;

        }
                 t++;
        if( n%3==0)
        {

            cout << "\t\t\t"<<t<<". Number is Divided By 3."<<endl;

        }
        else
        {

            cout << "\t\t\t"<<t<<". Number isn't Divided by 3."<<endl;

        }
     t++;
        if( n%5==0)
        {
            cout << "\t\t\t"<<t<<". Number is Divided By 5."<<endl;

        }
        else
        {
            cout << "\t\t\t"<<t<<". Number isn't Divided by 5."<<endl;

        }

    }
    t++;
    if(n>( MinInput+MaxInput)/2)

        cout << "\t\t\t"<<t<<". Number is situated in last half."<<endl;
    else
        cout << "\t\t\t"<<t<<". Number is situated in first half."<<endl;

    return ;
}

