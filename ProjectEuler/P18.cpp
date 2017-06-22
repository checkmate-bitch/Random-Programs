/*Find the maximum total from top to bottom of the triangle below:

{75}
{5,64}
{17,47,82}
{18, 35, 87,10}
{20, 04, 82, 47, 65}
{19, 01, 23, 75, 03, 34}
{88 ,02 ,77 ,73 ,07 ,63, 67}
{99, 65, 04, 28, 06, 16, 70, 92}
{41 ,41 ,26 ,56 ,83 ,40 ,80 ,70 ,33}
{41, 48, 72, 33, 47, 32, 37, 16, 94, 29}
{53 ,71 ,44 ,65 ,25 ,43 ,91 ,52 ,97 ,51 ,14}
{70, 11, 33 ,28 ,77 ,73 ,17 ,78 ,39 ,68 ,17 ,57}
{91 ,71 ,52 ,38 ,17 ,14 ,91 ,43 ,58 ,50 ,27 ,29 ,48}
{63, 66 ,04 ,68 ,89 ,53 ,67 ,30 ,73 ,16 ,69 ,87 ,40 ,31}
{04 ,62 ,98 ,27 ,23 ,09 ,70 ,98 ,73 ,93 ,38 ,53 ,60 ,04 ,23}

eg:
3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

My 1st answer was= 1064(wrong btw)


ANSWER= 1074


*/
//treats number starting with 0 as an octal no
//the algo that i implemented is a called a greedy algorithm. The result is wrong. 
/* eg:
3
7 4
2 4 6
8 5 1 3
using greedy i get= 3+7+4+5= 19
but 3+7+2+8= 20
hence there is a path that gives a greater max and does not violate the question*/

#include<iostream>
#define max 15 
using namespace std;

int main()
{
	int a[][max]={{75},							
{95,64},
{17,47,82},
{18, 35, 87,10},
{20, 4, 82, 47, 65},
{19, 1, 23, 75, 3, 34},
{88 ,2 ,77 ,73 ,7 ,63, 67},
{99, 65, 4, 28, 6, 16, 70, 92},
{41 ,41 ,26 ,56 ,83 ,40 ,80 ,70 ,33},
{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
{53 ,71 ,44 ,65 ,25 ,43 ,91 ,52 ,97 ,51 ,14},
{70, 11, 33 ,28 ,77 ,73 ,17 ,78 ,39 ,68 ,17 ,57},
{91 ,71 ,52 ,38 ,17 ,14 ,91 ,43 ,58 ,50 ,27 ,29 ,48},
{63, 66 ,4 ,68 ,89 ,53 ,67 ,30 ,73 ,16 ,69 ,87 ,40 ,31},
{4 ,62 ,98 ,27 ,23 ,9 ,70 ,98 ,73 ,93 ,38 ,53 ,60 ,4 ,23}};			

//my greedy solution

/*	int sum= a[0][0], hold= 0;
	for(int i= 1; i< max; i++)
	{
		cout<<"Current sum "<<sum<<endl;
		if(a[i][hold+1]>= a[i][hold])
		{
			sum+= a[i][hold+1];
			hold+= 1;
		}
		else sum+= a[i][hold];
	}
	cout<<"\nThe max sum of the triangle is "<<sum<<endl;*/

// In This we check the triangle from the penultimate row and go upwards

	//int a[][max]={{3}, {7,4}, {2,4,6}, {8,5,1,3}};
	for(int i= max- 2, k= 1; i>= 0; i--, k++)			//start at 2nd last row and go up
		for(int j= 0; j< max-k; j++)			
		{
			int sum= a[i][j];				//choose each element of that row as sum
			if(sum+a[i+1][j+1]>= sum+a[i+1][j])		//choose the greater number between the combination of sum and 
				sum+= a[i+1][j+1];			//the left or the right child
			else sum+= a[i+1][j];
			a[i][j]= sum;					//store it in the array itself so its self building
		}
	cout<<endl;
	cout<<"Max sum of the triangle is "<<a[0][0]<<endl;

//Brute Force Implementation
	
	return 0;
}

