#include<iostream>

using namespace std;

int getDigits(long int i, long int j, long int n)
{
	int count= 0;
	while(n> 0)
	{
		n/= 10;
		count++;
	}
	while(j> 0)
	{
		j/= 10;
		count++;
	}
	while(i> 0)
	{
		i/= 10;
		count++;
	}
	return count;
}

bool isPandigital(long int i, long int j, long int n)
{
	long int a= i, b= j, c= n;
	int arr[9], x= 0;
	while(a> 0)
	{
		arr[x++]= a% 10;
		a/= 10;
	}
	while(b> 0)
	{
		arr[x++]= b% 10;
		b/= 10;
	}
	while(c> 0)
	{
		arr[x++]= c% 10;
		c/= 10;
	}
	for(int i= 0; i< 9; i++)
		if(arr[i]== 0)
			return false;
	bool result= true;
	for(int i= 0; i< 9; i++)
		for(int j= i+1; j< 9; j++)
			if(arr[i]== arr[j])
				return false;
	return result;
}

int main()
{
	long int sum= 0;
	int digits;
	for(long int i= 101; i< 9999; i++)
		for(long int j= 2; j< 100; j++)
		{
			digits= getDigits(i,j,i*j);
			if(digits> 9)
				break;
			if(digits== 9)	
				if(isPandigital(i, j, i*j))
				{
					sum+= (i*j);
					cout<<i<<"\t"<<j<<endl;
				}
		}
	cout<<"Sum is "<<sum<<endl;
	return 0;
}
