#include<iostream>
#include<time.h>

using namespace std;

bool isPandigital(long long int n)
{
	/*long long int y= n, x= n;
	int count= 0;
	while(y> 0)
	{
		count++;
		y/= 10;
	}
	int a[count], i= 0;
	while(x> 0)
	{
		a[i++]= x%10;
		x/= 10;
	}
	for(i= 0; i< count -1; i++)
		for(int j= i+1; j< count; j++)
			if(a[j]> count || a[i]> count || a[j]== 0 || a[j]== a[i])
				return 0;
	return 1;*/
	int count= 0, a[10]= {0}, mul= 1;
	while(n> 0)
	{
		a[n%10]= !a[n%10];
		n/= 10;
		count++;
	}
	for(int i= 1; i<= count; i++)
		mul*= a[i];
	return mul;
}

bool isPrime(long long int n)
{
	for(int i= 3; i*i<= n; i+= 2)
		if(n%i== 0)
			return 0;
	return 1;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	long long int max= 2143;
	for(long long int i= 7123457; i<= 7654321; i+= 2)		//all 8 and 9 digit no's are divisible by 3
	{
		if(isPrime(i))
			if(isPandigital(i))
				if(i> max)
					max= i;
	}
	cout<<max<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
