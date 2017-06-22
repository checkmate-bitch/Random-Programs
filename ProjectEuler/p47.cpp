//does the job but slow
#include<iostream>
#include<time.h>

using namespace std;

/*bool compare(int a[])
{
	int count= 0;
	for(int i= 0; i< 100000; i++)
	{
		if(a[i]> 0)
			count++;
		if(count> 4)
			return 1;
	}
	if(count== 4)	return 0;
	else return 1;
}*/
 
int factorize(int n)
{
	int x= n, count= 0;
	for(int i= 2; x>1; i++)
	{
		if(x%i== 0)
		{
			count++;
			while(x%i== 0)
				x/= i;
		}
	}
	return count;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	int count= 0;
	for(int i= 2*3*5*7;; i++)			//since it requires 4 distinct no i cannot be less than 2,3,5,7
	{
		if(factorize(i)== 4)
			count++;
		else count= 0;
		if(count== 4)
		{
			cout<<i-3<<endl;
			break;
		}	
	}	
	t2= clock();
	float diff= ((float) t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
