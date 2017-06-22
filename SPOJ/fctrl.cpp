#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;

int getZero(int n)
{
	int sum= 0;
	for(int i= 1; pow(5, i)<= n; i++)
		sum+= (n/pow(5,i));
	return sum;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	int t;
	cin>>t;
	int n[t], i= 0;
	for(int i= 0; i< t; i++)
		cin>>n[i];
	i= 0;
	while(t--)
		cout<<getZero(n[i++])<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
