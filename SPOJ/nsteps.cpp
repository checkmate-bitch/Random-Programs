#include<iostream>
#include<time.h>

using namespace std;

int coordinate(int x, int y)
{
	if(x== y || x== y+2)
		if(x%2 == 0)
			return x+y;
		else return x+y-1;
	else return -1;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	int n;
	cin>>n;
	int a[2*n];
	for(int i= 0; i< 2*n; i++)
		cin>>a[i];
	int i= 0;
	while(n--)
	{	
		int x= coordinate(a[i], a[i+1]);
		if(x>= 0)
			cout<<x<<endl;
		else cout<<"No Number\n";
		i+= 2;
	}
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<" time taken is "<<diff<<" seconds\n";
	return 0;
}
