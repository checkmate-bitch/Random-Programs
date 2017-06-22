#include<iostream>

using namespace std;

int getCard(float n)
{
	int count= 0;
	float sum= 0.00;
	//cout<<n<<endl;
	for(float i= 2; sum< n; i++)
	{
		sum+= 1/i;
		//cout<<"present sum= "<<sum<<endl;
		count++;
	}
	return count;
}

int main()
{
	float n;
	while(1)
	{
		cin>>n;
		if(n== 0)
			break;
		cout<<getCard(n)<<" card(s)"<<endl;	
	}
	return 0;
}
