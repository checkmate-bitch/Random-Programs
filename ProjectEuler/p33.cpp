#include<iostream>
#include<time.h>

using namespace std;

float get(int x, int y)
{
	float n, m;
	if(x%10 == y%10)
	{
		n= x/10;
		m= y/10;
	}
	else if(x%10 == y/ 10)
	{
		n= x/10;
		m= y%10;
	}
	else if(x/10== y%10)
	{
		n= x%10;
		m= y/10;
	}
	else if(x/10 == y/10)
	{
		n= x%10;
		m= y%10;
	}
	else	return -1;
	return n/m;
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	int den= 1, num= 1;
	for(int i= 10; i< 100; i++)
	{
		if(i%10!= 0)
		{
			for(int j= i+1; j< 100; j++)
			{
				float no= 0;
				if(j%10!= 0)
				{
					no= (float)i/(float)j;
					if(no== get(i, j))
					{
						cout<<"i= "<<i<<"\tj= "<<j<<endl;
						num*= i;
						den*= j;
					}
				}
			}
		}
	}
	cout<<"fraction is "<<(float)num/den<<"\t for num= "<<num<<"\t den= "<<den<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
