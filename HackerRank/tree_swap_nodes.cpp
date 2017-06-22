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

int get_height( node *root )
{
  if( root == NULL )
    return 0;

  int h_l = 1 + get_height( root -> left );
  int h_r = 1 + get_height( root -> right );

  return h_l >= h_r ? h_l : h_r;
}
  
void level_change( node *root, int level, int target )
{
  if( root == NULL )
    return;
  // cout << "enter level_change\n";
  if( level == target )
  {
      // cout << "data : " << root -> data << "\tfor level : " << level << endl;
      node *temp = root -> left;
      root -> left = root -> right;
      root -> right = temp;
      return;
  }

  level_change( root -> left, level + 1, target );
  level_change( root -> right, level + 1, target );
}
  
void inorder( node *root )
{
  if( root == NULL )
    return;
  inorder( root -> left );
  cout << root -> data <<"\t";
  inorder( root -> right );
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
    int a, b;
    cin >> a >> b;
    tree[i] -> data = i+1;
    if( a == -1 )
      tree[i] -> left = NULL;
    else tree[i] -> left = tree[k++];
    if( b == -1 )
      tree[i] -> right = NULL;
    else tree[i] -> right = tree[k++];
  }
  // inorder( tree[0] );
  int tree_height = get_height( tree[0] );
  // cout << "height of tree = " << tree_height << "\n";
  int t;
  // cout << " t ? ";
  cin >> t;
  while( t-- )
  {
    int h, i = 1;
    cin >> h;
    while( h * i <= tree_height ){ 
      // cout << "many\n";
      level_change( tree[0], 1, h * i );
      i++;
    }
    inorder( tree[0] );
    cout << endl;
  }

  delete[] tree;

  return 0;
}
