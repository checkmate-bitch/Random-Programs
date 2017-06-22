#include<iostream>
#include<time.h>

using namespace std;

bool isPrime(int n)
{
	for(int i= 3; i*i<= n; i+= 2)
		if(n%i== 0)
			return 0;
	return 1;
}

void sort(int a[] , int size)
{
	for(int i= 0; i< size; i++)
	{
		int x= a[i], b[4], k= 0;
		while(x>0)
		{
			b[k++]= x%10;
			x/= 10;
		}
		//cout<<"before sort\n";
		//for(int d= 0; d< k; d++)
		//	cout<<b[d];
		//cout<<endl;
		for(int j= 0; j< 3; j++)
		{
			int min= b[j], flag= -1;
			for(int l= j+1; l< 4; l++)
				if(b[l]< min)
				{
					min= b[l];
					flag= l;
				}
			if(flag!= -1)
			{
				int temp= b[j];
				b[j]= min;
				b[flag]= temp;
			}
		}
		//if(b[0]== 1 && b[1]== 4)
		//	cout<<b[0]<<b[1]<<b[2]<<b[3]<<endl;
		//cout<<"after sort\n";
		//for(int d= 0; d< k; d++)
		//	cout<<b[d];
		//cout<<endl;	
		int len= 0, y= 0;
		while(len< 4)
		{
			y= y*10+ b[len];
			len++;
		}
		if(y== 1478)	
			cout<<"yes\n";
		//cout<<y<<" integer after sort\n";
		a[i]= y;
	}
	/*for(int i= 0; i< size; i++){
		if(a[i]>1000)
			cout<<a[i]<<"\t";
		if(a[i]== 1478)
			cout<<"\nwith 1487\n";}
	cout<<endl;*/
}

void getNo(int a[], int b[], int size)
{
	int hold[10]= {0};
	for(int i= 0; i< size-1; i++)
	{
		int count= 1;
		hold[0]= i;
		for(int j= i+1, k= 1; j< size; j++)
		{
			if(b[i]== b[j])
			{
				count++;
				hold[k++]= j;
			}	
		}
		if(count== 3)
		{
			if(a[hold[2]]- a[hold[1]] == a[hold[1]]- a[hold[0]]){
			for(int l= 0; l< 3; l++)
				cout<<a[hold[l]]<<" ";
			cout<<endl;}
		}
	}
}

int main()
{
	clock_t t1, t2;
	t1= clock();
	int index= 0, a[9000]= {0}, b[9000]= {0};
	for(int i= 1001; i< 10000; i+= 2)
		if(isPrime(i))
		{
			a[index]= b[index]= i;
			index++;
		}
	//for(int i= 0; i< index; i++)
	//	cout<<a[i]<<"\t";
	//cout<<endl;
	sort(b, index);
	getNo(a, b, index);
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"time taken is "<<diff<<" seconds\n";
	return 0;
}
