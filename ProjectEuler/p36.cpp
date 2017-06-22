#include<iostream>
#include<time.h>

#define max 1000000

using namespace std;

bool isPalindrome(int n)
{
	int x= n, num= 0;
	while(x> 0)
	{
		num= num*10+(x%10);
		x/= 10;
	}
	if(num== n)
		return true;
	return false;
}

void getBinary(int a[], int n)
{
	int i= 0;
	while(n> 0)
	{
		a[i++]= n% 2;
		n/= 2;
	}
}

bool isBinPalindrome(int n)
{
	int x= n, count= 0;
	while(x> 0)
	{
		x/= 2;
		count++;
	}
	int a[count], b[count];
	getBinary(a, n);
	for(int i= 0, j= count-1; i< count; i++, j--)
		b[i]= a[j];
	for(int i= 0; i< count/2; i++)
		if(a[i]!= b[i])
			return false;
	return true;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	int sum= 1;
	for(int i= 3; i< max; i+= 2)
		if(isPalindrome(i))
			if(isBinPalindrome(i))
				sum+= i;
	cout<<"Sum is "<<sum<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/ CLOCKS_PER_SEC;
	cout<<"Time taken is "<<diff<<" seconds\n";
	return 0;
}
