#include<iostream>
#include<string>

using namespace std;

void process(string str)
{
	for(unsigned int i= 0; i< str.size(); i++)
	{
		if(str.at(i)== 'm')	
			i+= 6;
		else
		{
			
int main()
{
	int t;
	cin>>t;
	while(t)
	{
		string s;
		cin>>s;
		if(s.size()> 4)
		{
			process(s);
			t--;
		}
	}	
	return 0;
}
	
