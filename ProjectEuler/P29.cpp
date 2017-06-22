//using brute force
//making my own list datatype 

#include<iostream>
#include<cmath>
#include<time.h>

using namespace std;

class node
{
	double info;
	node* next;
	public:
	void insertNode(node *&head, double data);
	void removeNode(node *&head);
	bool search(node *&head, double data);
	void printNode(node *&head);
	int sizeNode(node *head);
};

void node:: insertNode(node *&head, double data)
{
	node *ptr= new node;
	ptr->next= NULL;
	ptr->info= data;
	if(head== NULL)
		head= ptr;
	else{
		node *temp= head;
		while(temp->next!= NULL)
			temp= temp->next;
		temp->next= ptr;
	}
}

void node:: removeNode(node *&head)
{
	if(head== NULL)
	{
		cout<<"Empty List\n";
		return;
	}
	if(head->next== NULL)
	{
		node *temp= head;
		head= NULL;
		delete temp;
	}
	else
	{
		node *temp= head->next, *t2= head;
		while(temp->next!= NULL)
		{
			temp= temp->next;
			t2= t2->next;
		}
		t2->next= NULL;
		delete temp;
	}
}

void node:: printNode(node *&head)
{
	if(head== NULL)
	{
		cout<<"Empty List\n";
		return ;
	}
	node *temp= head;
	while(temp!= NULL)
	{
		cout<<temp->info<<"\t";
		temp= temp->next;
	}
	cout<<"\n";
}

bool node:: search(node *&head, double data)
{
	if(head== NULL)
		return false;
	else
	{
		node *temp= head;
		while(temp!= NULL)
		{
			if(temp->info== data)
			{
				return true;
			}
			temp= temp->next;
		}
	}
	return false;
}

int node:: sizeNode(node *head)
{
	if(head== NULL)
		return 0;
	else 
	{
		return 1+ sizeNode(head->next);
	}
}
			
class list
{
	node n, *head;
	public:
	list()
	{
		head= NULL;
	}
	void add(double data){	n.insertNode(head, data);}
	void remove(){	n.removeNode(head);}
	bool contains(double data){  return n.search(head, data);}
	void print(){	n.printNode(head);}
	int size(){	return n.sizeNode(head);}
	~list()
	{
		while(head!= NULL)
			remove();
	}
};
	
bool confirm(double d, double a[], int k)
{
	for(int i= 0; i< k; i++)
		if(d== a[i])
			return true;
	return false;
}
 
int main()
{
	clock_t t1, t2;
	t1= clock();
	list l;
	for(int i= 2; i< 101; i++)
		for(int j= 2; j< 101; j++)
		{
			double res= pow(i,j);
			if(!l.contains(res))
			{
				  l.add(res);
			}
		}
	cout<<"The total number of distinct numbers are "<<l.size()<<endl;
	t2= clock();
	float diff( ((float)t2- (float)t1)/CLOCKS_PER_SEC);
	cout<<diff<<endl;

	/*------------Using arrays-----------*/				
	double a[99*99]; int k= 0; 
	t1= clock();
	for(int i= 2; i< 101; i++)
                for(int j= 2; j< 101; j++)
                {
                        double res= pow(i,j);
                        if(!confirm(res, a, k))
                        {
			         a[k++]= res;
                        }
                }
	cout<<"The total number of distinct numbers are "<<k<<endl;
	t2= clock();
	diff= ((float)t2- (float)t1)/CLOCKS_PER_SEC;
	cout<<diff<<endl;
	//for(int i= 0; i< k; i++)
	//	cout<<a[i]<<"  ";
	return 0;
}
