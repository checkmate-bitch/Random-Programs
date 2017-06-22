#include<iostream>

using namespace std;

void input(int a[], int size)
{
	for(int i= 0; i< size; i++)
		cin>>a[i];
}

void sort(int a[], int size)
{
	int i= 1;
	while(i< size)
	{
		int key= a[i];
		int j= i-1;
		while(key< a[j] && j>= 0)
		{
			a[j+1]= a[j];
			j--;
		}
		a[j+1]= key;
		i++;
	}
}
		
int hotness(int m[], int l[], int size)
{
	int sum= 0;
	for(int i= 0; i< size; i++)
		sum+= (m[i]*l[i]);
	return sum;
}

int main()
{
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int m[n], l[n];
		input(m, n);
		input(l, n);
		sort(m, n);
		sort(l, n);
		cout<<hotness(m, l, n)<<endl;
	}
	return 0;
}
