#include<iostream>
#include<time.h>

using namespace std;

int isPandigital(int m, int n)
{
	int a[9], i= 0;
	while(n> 0)
	{
		a[i++]= n%10;
		n/= 10;
	}
	while(m> 0)
	{
		a[i++]= m%10;
		m/= 10;	
	}
	for(int i= 0; i< 8; i++)
		for(int j= i+1; j< 9; j++)
			if(a[i]== a[j] || a[j]== 0)
				return 0;
	n= 0; i= 8;
	while(i>= 0)
		n= n*10+a[i--];
	return n;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	int max= 918273645, n;
	for(int i= 9001; i< 10000; i++)
	{
		n= isPandigital(i, i*2);
		if(n> max)
			max= n;
	}
	cout<<max<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;	
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
