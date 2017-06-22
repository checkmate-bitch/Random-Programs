#include<iostream>

using namespace std;

long long int get_max_coins(long long int n)
{
    if(n > 1)
    {
        long long int a = get_max_coins(n/4);
        long long int b = get_max_coins(n/3);
        long long int c = get_max_coins(n/2);
        //cout<<"For n= "<<n<<"\ta= "<<a<<"\tb= "<<b<<"\tc= "<<c<<endl;
        return (n > a+b+c ? n : a+b+c);
    }
    return n;
}

int main()
{
    int t;
    cin >> t;
    while( t-- ){
    long long int n;
    // cout<<"enter a no\n";
    cin>>n;
    // cout<<"The total coins you can get is "<<get_max_coins(n)<<endl;
    cout << get_max_coins( n ) << endl;
    }
    return 0;
}
