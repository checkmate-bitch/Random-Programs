#include<iostream>
#include<math.h>
#include<time.h>

using namespace std;

bool isPrime(int n)
{
	if(n== 1)	return 0;
	if(n%2== 0 && n!= 2)
		return 0;
	for(int i= 3; i*i<= n; i+= 2)
		if(n%i== 0)
			return 0;
	return 1;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	bool b;
	int n, m, x, sum= 0, digits, count= 0, limit;
	for(int i= 23;; i+= 2)
	{
		b= true;
		n= m= x= i;
		digits= 0;
		while(x> 0)
		{
			x/= 10;
			digits++;
		}
		limit= pow(10, digits- 1);
		while(n> 0)
		{
			if(isPrime(n) && isPrime(m))
			{
				n/= 10;
				while(m> limit)
					m-= limit;
				limit/= 10;
			}
			else 
			{
				b= false;
				break;
			}
		}
		if(b)
		{
			sum+= i;
			count++;
			//cout<<i<<endl;
		}
		if(count== 11)
			break;
	}
	cout<<"SUm is "<<sum<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"Time taken is "<<diff<<" sec\n";
	return 0;
}
