#include<iostream>
#include<time.h>

using namespace std;

int factorial(int n)
{
	if(n== 1 || n== 0)
		return 1;
	else return factorial(n-1)*n;
}

int factorialSum(int n)
{
	int x= 0;
	while(n> 0)
	{
		x+= factorial(n%10);
		n/= 10;
	}
	return x;
}

int main()
{
	int sum= 0, hold;
	clock_t t1, t2;
	t1= clock();
	for(int i= 10; i< 400000; i++)
	{
		hold= factorialSum(i);
		if(hold== i)
			sum+= hold;
	}
	cout<<"Sum produced is= "<<sum<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"Time taken is "<<diff<<endl;
	return 0;
}
