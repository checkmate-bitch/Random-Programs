//problem 5 spoj

#include<iostream>
#include<string>

using namespace std;

bool palindrome(int x[], int size)
{
	int a[size], flag= 0;
	for(int i= 0; i< size; i++)
		if(x[i]!= 0)
		{
			flag= 1;
			break;
		}
	if(!flag)
		return flag;
	for(int i= 0, k= size- 1; i< size; i++, k--)
		a[k]= x[i];
	//cout<<"palindrome reverse array\n";
	//for(int i= 0; i< size; i++)
	//	cout<<a[i];
	//cout<<endl;
	for(int i= 0; i< size; i++)
		if(a[i]!= x[i])
			return 0;
	return 1;
}

void shift(int x[], int &size)
{
	//cout<<"Inside shift\n";
	size+= 1;
	for(int i= 1; i< size; i++)
		x[i]= 0;
	x[0]= 1;
}

void incTillPalindrome(int x[], int &size)
{
	int i= size-1;
	//cout<<"incTillPal size: "<<size<<endl;
	while(1)
	{
		x[i]= x[i]+1;
		//cout<<"x[i]= "<<x[i]<<"\n";
		while(x[i]== 10)
		{
			x[i]= 0;
			i--;
			x[i]= x[i]+1;
			if(i== 0 && x[i]== 10)
				shift(x, size);
		}
		i= size-1;
		/*cout<<"inc Till Palindrome x\n";
		for(int j= 0; j< size; j++)
			cout<<x[j];
		cout<<endl;*/
		if(palindrome(x, size))
			break;
	}
}

string getPalindrome(string a)
{
	int n[a.length()];				//storing all digits of the string
	for(unsigned int i= 0; i< a.length(); i++)
		n[i]= (int)a.at(i)- 48;
	int i= 0, k= 0, j= 0;
	while(1)
	{
		if(n[i++]== 0)
			j++;
		else break;
	}
	int new_size= (signed)a.length()- j;
	//cout<<n[0]<<endl;
	//cout<<"j= "<<j<<endl;
	//cout<<"size= "<<new_size<<endl;
	int s[new_size];
	for(i= j, k= 0; i< (signed)a.length(); i++, k++)
		s[k]= n[i]; 
	int x[new_size+1];				//will contain the next palindrom
	for(i= 0; i< new_size; i++)
		x[i]= s[i];
	/*cout<<"array s is\n";
	for(i= 0; i< new_size; i++)
		cout<<s[i];
	cout<<endl;
	cout<<"array x is\n";
	for(i= 0; i< new_size; i++)
		cout<<x[i];
	cout<<endl;*/
	incTillPalindrome(x, new_size);
	string str= "";
	/*cout<<"make string\n";
	for(i= 0; i< new_size; i++)
		cout<<x[i];
	cout<<endl;*/
	for(i= 0; i< new_size; i++)
		str+= (x[i]+48);
	return str;	
}
	
int main()
{
	int t, i= 0;
	cout<<"Enter test cases ";
	cin>>t;
	string a[t], hold[t];				//hold[t] stores the palindrome for corresponding a[t]
	for(int j= 0; j< t; j++)
		cin>>a[j];
	while(t-->0)
	{
		hold[i]= getPalindrome(a[i]);
		cout<<hold[i]<<endl; 
		i++;
	}
	return 0;
}
