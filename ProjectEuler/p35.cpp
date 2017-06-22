//instead of continously calculating the digits we can store the times in an array; may speed up

#include<iostream>
#include<time.h>
#define max 1000000
using namespace std;

bool isPrime(int n)
{
	if(n%2== 0)
		return 0;
	for(int i= 3; i*i<= n; i+= 2)
		if(n%i== 0)
			return 0;
	return 1;
}

int getDigit(int n)
{
	int count= 0;
	while(n> 0)
	{
		count++;
		n/= 10;
	}
	return count;
}

int rotate(int n, int size)
{
	int x= n, a[size], i= 0;
	while(x> 0)
	{
		a[i++]= x% 10;
		x/= 10;
	}
	for(i= 0; i< size- 1; i++)
	{
		int temp= a[i];
		a[i]= a[i+1];
		a[i+1]= temp;
	}
	while(size--> 0)
		x= x*10+ a[size];
	return x;
}
	
bool isRotatePrime(int n)
{
	int num= n, times= getDigit(n);				//no of times to be rotated
	for(int i= 0; i< times; i++)
	{
		num= rotate(num, times);
		if(!isPrime(num))
			return false;
	}
	return true;
}
		
int main()
{
	clock_t t1, t2;
	t1= clock();
	int count= 1;
	for(int i= 3; i< max; i+= 2)
		if(isPrime(i))
			if(isRotatePrime(i))
				count++;
	cout<<count<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"Time taken is "<<diff<<" seconds\n";
	return 0;
}
