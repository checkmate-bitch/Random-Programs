//does not work not optimised enough
#include<iostream>
#include<time.h>

using namespace std;

bool pentagonal(int n)
{
	int no= 0;
	for(int i= 100; no< n; i++)
		no= (i*(3*i-1))/2;
	if(no== n)
		return 1;
	else return 0;
}
 
int main()
{
	clock_t t1, t2;
	t1= clock();
	int d= 0, sum= 0, diff= 1000;
	for(int i= 1000;i< 10000; i++)
	{
		sum= 0, diff= 0;
		for(int j= i+1;j< i+1000; j++)	
		{
			sum= (i*(3*i-1))/2+ (j*(j*3- 1))/2;
			if(pentagonal(sum))
			{
				//cout<<"sum= "<<sum<<endl;
				diff= (j*(3*j-1))/2 - (i*(3*i-1))/2;
				diff= diff>0? diff: -diff;
				if(pentagonal(diff))
					break;
			}
		}
		if(diff< d)
			d= diff;
	}
	cout<<d<<endl;
	t2= clock();
	float ff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<ff<<" seconds\n";	
	return 0;
}
