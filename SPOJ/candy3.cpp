#include<iostream>

using namespace std;

int main()
{
	long long int t, n;
	cin>>t;
	while(t--)
	{
		cin>> n;
		unsigned long long int a[n];
		for(int i= 0; i< n; i++)
			cin>>a[n];
		unsigned long long int sum= 0;
		for(int i= 0; i< n; i++)
			sum+= a[i]%n;
		if(sum== 0)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
