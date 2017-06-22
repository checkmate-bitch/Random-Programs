//Ans- 840;   Incorrect answer i get 420
//now working 

#include<iostream>
#include<time.h>

using namespace std;

bool rightTriangle(int a, int b, int c)
{
	if(a*a+b*b== c*c)
		return 1;
	return 0;
}

void getMax(int a[])
{
	int max= a[0], flag;
	for(int i= 1; i< 1000; i++)
	{
		if(a[i]> max)
		{
			max= a[i];
			flag= i;
		}
	}
	cout<<"for p= "<<flag<<"\tmax= "<<a[flag]<<endl;
}

int main()
{
	clock_t t1, t2, t3, t4;
	t1= clock();
	int a[1000]= {0};
	for(int i= 2; i< 1000; i++)
		for(int j= 1; j< i; j++)
		{	
			for(int k= i;; k++)
			{
				if(k*k> i*i+ j*j)
					break;
				if(i+j+k<= 1000){
					if(rightTriangle(i,j,k))
						a[i+j+k]++;}
				else break;	
			}
		}
	getMax(a);
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<< "seconds\n";
	t3= clock();
	int soln, max= 0, res;
	for(int p= 2; p< 1001; p++)
	{
		soln= 0;
		for(int b= 2; b< p; b++)
		{
			if((p*p-2*b*p)%(2*p- 2*b)== 0)
			{
				soln++;;
			}
		}
		if(soln> max)
		{
			max= soln;
			res= p;
		}
	}
	cout<<"for p= "<<res<<"\t max= "<<max<<endl;
	t4= clock();
	float r= ((float)t4- (float)t3)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<r<<" seconds\n";
	return 0;
}
