#include<iostream>
#include<string.h>

using namespace std;

string getCode(int col, string str)
{
	int size= (signed)str.size();
	//cout<<"size is "<<size<<endl;
	string s= "";
	for(int a= 0, b= (2*col)-1; a< b; a++, b--)
	{	for(int i= a, j= b; i< size || j<size; i+= 2*col, j+= 2*col)
		{
			if(i<size)
				s+= str.at(i);
			if(j<size)
				s+= str.at(j);
		}
		//cout<<s<<"\ta="<<a<<"\tb="<<b<<endl;
	}
	return s;
}

int main()
{
	int n;
	string str;
	while(1)
	{
		cin>>n;
		if(n== 0)
			break;
		cin>>str;
		cout<<getCode(n, str)<<endl;
	}
	return 0;
}
