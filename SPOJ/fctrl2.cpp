#include<iostream>
#include<time.h>

using namespace std;

/*long long int factorial(int n)
{
	if(n==0 || n== 1)
		return 1;
	return n*factorial(n-1);
}*/

int main()
{
	clock_t t1 , t2;
	t1= clock();
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n> 1)
		{
			int a[10000]= {0}, i= 2, index= 0;
			a[0]= 1;
			while(i<= n)
			{
				int k= 0, temp= 0, x= 0;
				while(k<= index)
				{
					a[k]= a[k]*i+ temp;
					temp= 0;
					//cout<<"i= "<<i<<"\ta["<<k<<"]= "<<a[k]<<"\tindex= "<<index<<endl;
					if(a[k]> 9)
					{
						x= a[k];
						a[k]= x%10;
						temp= x/10;
						if(k== index)
							index++;
					}
					k++;
				}
				i++;
			}
			for(i= index; i>= 0; i--)
				cout<<a[i];
			cout<<endl;
		}
		else	cout<<1<<endl;
	}
	t2= clock();
	float diff= ((float) t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is  "<<diff<<" seconds\n";
	return 0;
}	
