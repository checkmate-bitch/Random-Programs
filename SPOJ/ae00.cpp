#include<iostream>

using namespace std;

int main()
{
	int n, sum= 0;
	cin>>n;
	if(n< 4)
		sum= n;
	else{
	for(int i= 1; i< n/2+1; i++)
		for(int j= i; j*i<= n; j++)
			sum+= 1;} 
	cout<<sum<<endl;
	return 0;
}
