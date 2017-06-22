#include<iostream>
#include<time.h>

using namespace std;

int main()
{
	clock_t t1, t2;
	t1= clock();
	long long int t= 285, p= 165, h= 143;
	long long int t_no= 0, p_no= 0, h_no= 0;
	while(h++)
	{
		h_no= h*(2*h-1);
		while(p_no< h_no)
		{
			p++;
			p_no= (p*(3*p-1))/2;	
		}
		if(p_no== h_no)
		{
			while(t_no< h_no)
			{
				t++;
				t_no= (t*(t+1))/2;
			}
			if(t_no == h_no)
				break;
		}
		cout<<"t_no= "<<t_no<<"\tp_no= "<<p_no<<"\th_no= "<<h_no<<endl;
	}
	cout<<t_no<<"\t at t= "<<t<<"\tp= "<<p<<"\th= "<<h<<endl;
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
