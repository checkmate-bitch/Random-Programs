#include<iostream>
#define mod 100000000

using namespace std;

//void inBinary(int a[], int n)
//{
	
int main()
{
	int t, base, temp;
	long long int exp;
	cin>>t;
	while(t--)
	{
		cin>>base>>exp;
		if(exp>0){
		temp= 1;
		/*for(long long int i= 1; i<= b; i++)
		{
			temp*= a;
			temp%= 10;
		}
		cout<<temp<<endl;*/
		while(exp> 0)
		{
			if(exp%2== 1)
				temp= (temp*base)%10;
				base= (base*base)%10;
				exp/= 2;
		}
		cout<<temp<<endl;
		}
		else	cout<<1<<endl;
	}
	return 0;
}		
