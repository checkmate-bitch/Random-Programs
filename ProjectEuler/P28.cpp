#include<iostream>
#define max 1001 
#define x ((max+1)/2)-1 

using namespace std;

int main()
{
        int a[max][max];
        a[x][x]= 1;
        int row= x, col= x, k= 0, j= 0;
        int ch[4]= {1, 2, 3, 4};
        for(int i= 2; i< max*max;)
        {
                switch(ch[j])
                {
                        case 1: {
                                        k++;
                                        if(k>= max)
                                                k-= 1;
                                        int n= k;
                                        while(n-->0)
                                        {
                                                col+= 1;
                                                a[row][col]= i++;
                                        }
                                }
                                j++;
                                break;
			 case 2: {
                                        int n= k;
                                        while(n--> 0)
                                        {
                                                row+= 1;
                                                a[row][col]= i++;
                                        }
                                }
                                j++;
                                break;
                        case 3: {
                                        k++;
                                        int n= k;
                                        while(n--> 0)
                                        {
                                                col-= 1;
                                                a[row][col]= i++;
                                        }
                                }
                                j++;
                                break;
                        case 4: {
                                        int n= k;
                                        while(n--> 0)
                                        {
                                                row-= 1;
                                                a[row][col]= i++;
                                        }
                                }
                                j++;
                                break;
                        default: cout<<"Shitty case\n";
                }
                if(j%4== 0)
                        j= 0;
        }
	int sum= 0;
	for(int i= 0; i< max; i++)
		for(int j= 0; j< max; j++)
			if(i==j || i+j==max-1)
				sum+= a[i][j]; 
	cout<<"Sum of the numbers on the diagonals are= "<<sum<<endl;

	/* We can find the solution without making the spiral :p
	   The elements on the diagonal have a pattern. THey make the following equation:
		1. Top Right= n^2
		2. Top Left= n^2-n+1
		3. Bottom Right= n^2-3n+3
		4. Bottom Left= n^2-2n+2
		adding= 4n^2-6n+6
	*/
	int new_sum= 0;
	for(int n= 3; n<= max; n+=2)
		new_sum+= 4*(n*n)-6*n+6;
	cout<<"\n2. Sum of numbers on the diagonals are "<<new_sum+1<<endl; 
	return 0;
}
