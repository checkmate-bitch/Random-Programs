#include<iostream>
#include<time.h>

#define start 1023456789

using namespace std;

bool isPandigital(long long int n)
{
	int mul= 1, count= 10, a[10]= {0};
	while(n> 0)
	{
		a[n%10]= !a[n%10];
		n/= 10;
	}	
	for(int i= 0; i< count; i++)
		mul*= a[i];
	return mul;
}

bool check(long long int n)
{
	int a[10], num, count= 9;// b[7]= {0}, k= 0;
	while(n> 0)
	{
		a[count--]= n%10;
		n/= 10;
	}
	for(int i= 1; i<= 7; i++)
	{
		num= 0;
		for(int j= i; j< i+3; j++)
			num= num*10+a[j];
		if(i==1)
			if(num%2!= 0)
				return 0;//b[k++]= 1;
		if(i==2)
			if(num%3!= 0)
				return 0;//b[k++]= 1;
		if(i==3)
			if(num%5!= 0)
				return 0;//b[k++]= 1;
		if(i==4)
			if(num%7!= 0)
				return 0;//b[k++]= 1;
		if(i==5)
			if(num%11!= 0)
				return 0;//b[k++]= 1;
		if(i==6)
			if(num%13!= 0)
				return 0;//b[k++]= 1;
		if(i==7)
			if(num%17!= 0)
				return 0;//b[k++]= 1;
	}
	/*int mul= 1;
	for(int i= 0; i< 7; i++)
		mul*= b[i];*/
	return 1;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	long long int sum= 0;
	for(long long int i= start; i<= 9876543210; i++)		
		if(isPandigital(i))
			if(check(i)){cout<<i<<endl;
				sum+= i;}
	cout<<sum<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
