//minimum steps from a number to 1 where the following operations are possible on the number: n-1, n/2, n/3

#include<iostream>
#include<ctime>
#define MIN(a,b,c) ((a < b) ? (a < c ? a : c) : (b < c ? b : c))

using namespace std;

int min_steps(int n)
{
    int a = n, b = n, c = n;
    if( n <= 1)
        return 0;
    if( n%3 == 0)
        a = min_steps(n/3);
    if( n%2 == 0)
        b = min_steps(n/2);
    c = min_steps(n-1);
    return 1+MIN(a,b,c);
}

int main()
{
    time_t t1,t2;
    t1 = clock();
    int n, res;
    cout<<"Enter a no\n";
    cin>>n;
    res = min_steps(n);
    cout<<"The steps taken = "<<res<<endl;
    t2 = clock();
    float diff = ((float)t2 - (float)t1)/CLOCKS_PER_SEC;
    cout<<"The time taken is "<<diff<<endl;
    return 0;
}
