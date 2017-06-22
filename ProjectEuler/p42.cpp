#include<iostream>
#include<time.h>
#include<fstream>
#include<string>

using namespace std;

bool isTriangleNo(string str)
{
	int sum= 0;
	//cout<<endl;
	for(int i= 0; i< (signed)str.length(); i++)
	{
		sum+= (str.at(i) - 'A')+1;
		//cout<<"cur sum "<<sum<<" for letter "<<str.at(i)<<"\n";
	}
	//cout<<endl;
	//cout<<"\nsum is "<<sum<<endl;
	int t_no= 0;
	for(int i= 1; t_no< sum; i++)
		t_no= (i*(i+1))/2; 
	if(t_no== sum)
		return 1;
	else return 0;
}
	
int main()
{
	clock_t t1, t2;
	t1= clock();
	ifstream file("/home/itachi_uchiha/Desktop/words.txt");
	if(file.is_open())
	{
		int count= 0;// i=0;
		cout<<"File opened\n";
		string str;
		while(getline(file, str, ','))
		//if(getline(file, str, ','))
		{
			str= str.substr(1, str.length()-2); 
			//cout<<str<<endl;
			if(isTriangleNo(str))
			{
				cout<<str<<endl;
				count++;
			}
		}
		cout<<"Total triangle words are "<<count<<endl;
	}
	else cout<<"cannot open file\n";
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
