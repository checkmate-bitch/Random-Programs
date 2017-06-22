#include<iostream>
#include<time.h>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	clock_t t1, t2;
	t1= clock();
	string str;
	stringstream my_str;
	for(int i= 1; i< 1000000; i++)
		my_str<<i;
	str= my_str.str();
	int m= 1;
	//cout<<str<<endl;
	for(int i= 0; i< 1000000; i++)
		if(i==0 || i==9 || i==99 || i==999 || i==9999 || i==99999 || i==999999)
			m*= ((int)str.at(i)- 48);		//you get the character at i. let 1 it gets converted to ascii. hence the formula 
	cout<<m<<endl;
	t2= clock();
	float d= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<d<<" seconds\n";
	return 0;
}
