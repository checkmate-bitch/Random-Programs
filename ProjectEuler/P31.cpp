//P31 euler

#include<iostream>
#include<time.h>

using namespace std;

int main()
{
	/*----------------Brute Force  1------------------*/
	/*clock_t t1, t2;
	t1= clock();
	int count= 0;
	for(int a= 0; a<= 200; a+= 200)
		for(int b= 0; b<= 200; b+=100)
			for(int c= 0; c<= 200; c+=50)
				for(int d= 0; d<= 200; d+=20 )
					for(int e= 0; e<= 200; e+=10)
						for(int f=0; f<= 200; f+= 5)
							for(int g= 0; g<= 200; g+=2)
								for(int h= 0; h<= 200; h+=1)
								{
									if(a+b+c+d+e+f+g+h== 200)
										count++;
								}
	t2= clock();
	float diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<"THe total number of ways is "<<count<<endl;
	cout<<"Total time= "<<diff<<endl;
	*/
	/*---------------------Brute Force 2-------------------*/
	clock_t t3, t4;
        t3= clock();
        int count= 0;
        for(int a= 0; a<= 200; a+= 200)
                for(int b= a; b<= 200; b+=100)
                        for(int c= b; c<= 200; c+=50)
                                for(int d= c; d<= 200; d+=20 )
                                        for(int e= d; e<= 200; e+=10)
                                                for(int f= e; f<= 200; f+= 5)
                                                        for(int g= f; g<= 200; g+=2)
                                                       		count++;
        t4= clock();
        float diff1= ((float)t4- (float)t3)/CLOCKS_PER_SEC;
        cout<<"THe total number of ways is "<<count<<endl;
        cout<<"Total time= "<<diff1<<endl;
	return 0;
}
