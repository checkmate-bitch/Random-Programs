#include<iostream>
#include<time.h>

using namespace std;

void reverse(int a, int &b)
{
	while(a> 0)
	{
		b= b*10+ a%10;
		a/= 10;
	}
}

int reverseAdd(int a, int b)
{
	int x= 0, y= 0;
	reverse(a, x);
	reverse(b, y);
	int sum= x+y, rev_sum= 0;
	reverse(sum, rev_sum);
	return rev_sum;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	int n;
	cin>>n;
	int a[2*n], i= 0;
	for(i= 0; i< 2*n; i+= 2)
		cin>>a[i]>>a[i+1];
	i= 0;
	while(n--)
	{
		cout<<reverseAdd(a[i],a[i+1])<<endl;
		i+= 2;
	}
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
