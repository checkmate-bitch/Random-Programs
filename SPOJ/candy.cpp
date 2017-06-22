#include<iostream>

using namespace std;

int getCandy(int size, int a[])
{
	int sum= 0;
	for(int i= 0; i< size; i++)
		sum+= a[i];
	if(sum%size== 0)
	{
		int count= 0,base= sum/size;
		for(int i= 0; i< size; i++)
			if(a[i]< base)
				count+= (base-a[i]);
		return count;
	}
	else return -1;
}

int main()
{
	int a[10001], n;
	while(1)
	{
		cin>> n;
		if(n== -1)
			break; 
		for(int i= 0; i< n; i++)
			cin>>a[i];
		cout<<getCandy(n, a)<<endl;
	}
	return 0;
}
