#include <iostream>

using namespace std;

class node
{
  int info;
  node *next;
  
  public:

  node(){ next = NULL; }

  void set_info( int data );
  int get_info();
  void set_next( node *ptr );
  node* get_next();
};

void node :: set_info( int data )
{
  info = data;
}

int node :: get_info()
{
  return info;
}

void node :: set_next( node *ptr )
{
  next = ptr;
}

node* node :: get_next()
{
  return next;
}

class stack
{
  node *head;
  node *top;

  public:

  stack()
  {
    head = NULL;
    top = NULL;
  }

  void push( int info );
  int get_top();
  void pop();
  node* get_head();
  void set_head( node* ptr );
  node* get_top_node();
  void set_top_node( node* ptr );
  void set_top_node_next( node *ptr , node *top_node);
};

void stack :: set_top_node_next( node *ptr , node *top_node)
{
  top -> set_next( ptr );
  top = top_node;
}

node* stack :: get_top_node()
{
  return top;
}

void stack :: set_top_node( node* ptr )
{
  top = ptr;
}

node* stack :: get_head()
{
  return head;
}

void stack :: set_head( node* ptr )
{
  head = ptr;
}

void stack :: push( int info )
{
  node* ptr = new node;
  ptr -> set_info( info );
  ptr -> set_next( NULL );
  if( head == NULL )
  {
    head = ptr;
    top = ptr;
    return;
  }
  top -> set_next( ptr );
  top = ptr;
}

int stack :: get_top()
{
  return top -> get_info();
}

void stack :: pop()
{
  node *temp = top;
  if( head == top )
  {
    head = NULL;
    top = NULL;
    return;
  }
  temp = head;
  while( temp -> get_next() != top )
    temp = temp -> get_next();
  top = temp;
  delete temp -> get_next();
  top -> set_next( NULL );
}

int main()
{
  int n;
  cin >> n;
  int *a = new int[n]; 
  for(int i= 0; i< n; i++)
    cin >> a[i];
  stack *s = new stack[n];
  int k = 0;
  s[k].push( a[0] ); 
  for(int i= 1; i< n; i++)
  {
    if( a[i] <= a[i - 1] )
    {
      s[k].push( a[i] );
    }
    else 
    {
      k++;
      s[k].push( a[i] );
    }
  }
  int count = 0;
  if( k > 0 )
  while( 1 )
  {
    bool flag = true;
    for(int i= 1; i<= k; i++)
    {
      if( s[i].get_head() )
        s[i].set_head( s[i].get_head() -> get_next() );
    }
    count++;
    for(int i= 1, j= 0; i<= k; i++)
    {
      if( s[i].get_head() && s[i].get_head() -> get_info() <= s[j].get_top() )
      {
        s[j].set_top_node_next( s[i].get_head(), s[i].get_top_node() );
        s[i].set_head( NULL );
      }
      else if( s[i].get_head() )  
      {
        j = i;
        flag = false;
      }
    }
    if( flag ) break;
  }
  
  cout << count;
  /*
   *
  for(int i= 0; i<= k; i++)
    cout << s[i].get_top() << '\n';
  */
  delete [] a;
  return 0;
}



/* 
 *  Working but not passing all test cases due to timeout
 *
 *  int main()
{
  int n;
  cin >> n;
  stack<int> s;
  int x;
  for(int i= 0; i< n; i++)
  {
    cin >> x;
    s.push(x);
  }

  int count = 0;
  int a[n];

  while(1)
  {
    int flag = true;
    int i= 0;
    while( !s.empty() )
    {
      int temp = s.top();
      s.pop();
      if( !s.empty() && s.top() < temp )
      {
        flag = false;
      }
      else  a[i++] = temp;
    }
    if( !flag )
    {
      for(int j= i-1; j >= 0; j--)
      {
        s.push(a[j]);
      }
      count++;
    }
    else break;
  }

  cout << count;

  return 0;
}
*/
