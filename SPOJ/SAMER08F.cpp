#include<iostream>
#include<math.h>

using namespace std;

int getSquares(int n)
{
	int sum= 0;
	for(int i= 1; i<= n; i++)
		sum+= pow(i, 2);
	return sum;
}

int main()
{
	int n= 1, a[100], i= 0;
	while(n)
	{
		cin>>a[i];
		n= a[i++];
	}
	for(int j= 0; j< i-1; j++)
		cout<<getSquares(a[j])<<endl;
	return 0;
}
	
