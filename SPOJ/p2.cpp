//problem 2

#include<iostream>
#define limit 1000000000
using namespace std;

void getprime(unsigned long int a[], int t)
{
	int x= 0;
	while(t--> 0)
	{
		if((a[x]<= limit && a[x]>=1) && (a[x+1]<= limit && a[x+1]>=1) && ((a[x+1]-a[x])<=100000))
		{
			for(unsigned long int i= a[x]; i<= a[x+1]; i++)
			{
				bool x= true; 
				if(i%2== 0 && i!= 2)
					x= false;
				if(i%2!= 0 && i!= 1)
				{
					for(unsigned long int j= 3; j*j<= i; j+=2)
					{				
						if(i%j== 0)
						{
							x= false;
							break;
						}
					}
				}
				if(x== true && i!= 1)
					cout<<i<<endl;	
			}	
		}
		x+=2;
		cout<<endl;
	}
}					
					 
int main()
{
	int t, i= 0;
	cin>>t;
	int x= t;
	if(t<= 10)
	{
		unsigned long int a[2*t];
		while(x-->0)
		{
			cin>>a[i++];
			cin>>a[i++];
		}
		cout<<endl;
		getprime(a, t);
	}
	return 0;
}
	
	
