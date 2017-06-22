#include<iostream>
#include<time.h>
#include<cmath>

using namespace std;

bool isPrime(int n)
{
	for(int i= 3; i*i<= n; i+= 2)
		if(n%i== 0)
			return 0;
	return 1;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	int b_index= 0, a_index= 0, c[10000], b[10000], a[10000];
	for(int i= 3; i< 10000; i+= 2)
	{
		if(isPrime(i))
			a[a_index++]= i;
		else b[b_index++]= i;
	}	
	for(int i= 1; i< 10000; i++)
		c[i]= 2*pow(i,2);
	for(int i= 0; i< b_index; i++)
	{
		int flag= 0;
		for(int j= 0; a[j]< b[i]; j++)
		{
			for(int k= 0; a[j]+c[k]<= b[i]; k++)
			{
				if(a[j]+c[k]== b[i])
				{
					cout<<"for the odd composite "<<b[i]<<"\tprime "<<a[j]<<"\tand constant "<<c[k]<<endl;
					flag= 1;
					break;
				}
			}
			if(flag)	break;
		}
		if(!flag)
		{
			cout<<b[i]<<endl;
			break;
		}
	}
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	clock_t t3, t4;
	t3= clock();
	for(int i= 0; i< b_index; i++)
	{
		int flag= 0;
		for(int j= 0; b[i]-c[j]>= 3; j++)
		{
			if(isPrime(b[i]- c[j]))
			{
				flag= 1;
				break;
			}
		}
		if(!flag)
		{
			cout<<b[i]<<endl;
			//break;
		}
	}
	t4= clock();
	diff= ((float)t4- (float)t3)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
