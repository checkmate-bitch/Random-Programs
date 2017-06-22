#include<iostream>
#include<time.h>

#define lim 1000000

using namespace std;

bool isPrime(int n)
{
	for(int i= 3; i*i<= n; i++)
		if(n%i == 0)
			return 0;	
	return 1;
}

int check(int a[] ,int n, int beg, int size)
{
	int count= 0, sum= 0;
	for(int i= beg; i< size; i++)
	{
		sum+= a[i];
		count++;
		if(sum== n)
			return count;
		if(sum> n)
			break;
	}
	return 0;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	int primes[80000]= {0}, count= 1, max= 0, no= 0;
	primes[0]= 2;
	for(int i= 3; i< lim; i+= 2)
		if(isPrime(i))
			primes[count++]= i;
	cout<<"Total elements\t"<<count<<endl;
	for(int i= count-1; i>= 60000; i--)
		for(int j= 0; j< count; j++)
		{
			if(primes[i]> primes[j])
			{
				int temp= check(primes, primes[i], j, count);
				if(temp> max)
				{
					cout<<primes[i]<<" has count "<<temp<<endl;
					no= primes[i];
					max= temp;
				}
			}
		}
	cout<<"Prime is "<<no<<" for a count of "<<max<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
