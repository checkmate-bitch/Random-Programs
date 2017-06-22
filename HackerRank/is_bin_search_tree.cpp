#include<iostream>

using namespace std;

class node
{

  public:

  int data;
  node *left;
  node *right;

  node()
  {
    data = 0;
    left = NULL;
    right = NULL;
  }
  
};

bool check_bst( node *root )
{
  if( root -> left == NULL && root -> right == NULL )
    return true;
  if( root -> left && root -> right )
  {
    if( root -> data > root -> left -> data && root -> data < root -> right -> data )
    {
      check_bst( root -> left );
      check_bst( root -> right );
    }
    else return false;
  }
  else if( root -> left && root -> right == NULL )
  {
    if( root -> data > root -> left -> data )
    {
      check_bst( root -> left );
    }
    else return false;
  }
  else if( root -> right && root -> left == NULL )
  {
    if( root -> data < root -> right -> data )
    {
      check_bst( root -> right );
    }
    else return false;
  }
  else return true;
}

int main()
{
  int n;
  // cout << " n ? ";
  cin >> n;
  node *tree[n];
  for( int i= 0; i< n; i++ )
    tree[i] = new node();

  int k = 1;
  for(int i= 0; i< n; i++)
  {
    int a, b, val;
    cout << "node data \n";
    cin >> val;
    cout << "node children \n";
    cin >> a >> b;
    tree[i] -> data = val;
    if( a == -1 )
      tree[i] -> left = NULL;
    else tree[i] -> left = tree[k++];
    if( b == -1 )
      tree[i] -> right = NULL;
    else tree[i] -> right = tree[k++];
  }

  if( check_bst( tree[0] ) )
    cout << "The tree is a BST\n";
  else cout << "The tree is something else\n";

  for( int i= 0; i< n; i++ )
    delete tree[i];
  return 0;
}
