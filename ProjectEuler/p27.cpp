#include<iostream>
#include<time.h>

using namespace std;

bool isPrime(int n)
{
	if(n%2== 0 || n< 2) 
		return 0;
	if(n== 2 || n== 3|| n== 5 || n== 7)
		return 1;
	for(int i= 3; i*i<= n; i+= 2)
		if(n%i== 0)
			return 0;
	return 1;
}

int getConsecutivePrime(int a, int b)
{
	int count= 1, n= 1;
	while(1)
	{
		if(isPrime(n*n+a*n+b))
		{
			n++;
			count++;
		}
		else	break;
	}
	if(a== -61 && b== 971)
		cout<<"This count "<<count<<endl;
	return count;
}

int main()
{
	clock_t t1,t2;
	t1= clock();
	int max= 0, a= 0, b= 0, count= 0;
	for(int i= -1000; i<= 1000; i++)
	{
		for(int j= 2; j<= 1000; j++)
		{
			count= 0;
			if(isPrime(j))
				count= getConsecutivePrime(i, j);
			if(count> max)
			{
				max= count;
				a= i;
				b= j;
				//cout<<"a= "<<a<<"\tb= "<<b<<"\tcount= "<<count<<endl;
			}
		}
	}
	cout<<"a= "<<a<<"\tb= "<<b<<"\tand the product= "<<a*b<<"\tfor a max of "<<max<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
