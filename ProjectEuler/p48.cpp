#include<iostream>
#include<time.h>

using namespace std;

int main()
{
	clock_t t1, t2;
	t1= clock();
	long long int mod= 10000000000, result= 0;
	for(int i= 1; i<= 1000; i++)
	{
		long long int temp= i;
		for(int j= 1; j< i; j++)
		{
			temp*= i;
			temp%= mod;
		}
		result+= temp;
		result%= mod;
	}
	cout<<"result is "<<result<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
