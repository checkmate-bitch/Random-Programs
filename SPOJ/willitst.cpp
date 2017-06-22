#include<iostream>

using namespace std;

int main()
{
	unsigned long long int n;
	cin>>n;
	while(n>1)
	{
		if(n%3== 0)
			break;
		if(n%2== 0)
			n/= 2;
		else n= 3*n+3;
		//cout<<n<<endl;
	}
	if(n== 1)
		cout<<"TAK\n";
	else cout<<"NIE\n";
	if(n & (n-1) == 0)
		cout<<"TAK\n";
	else cout<<"NIE\n";
	return 0;
}
