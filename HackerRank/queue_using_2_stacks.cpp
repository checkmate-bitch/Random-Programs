#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int n, x, num;
  stack<int> s1, s2;
  cin >> n;
  while( n-- )
  {
    cin >> x;
    if( x == 1 )
    {
      cin >> num;
      s1.push( num );
    } 
    else if( x == 2 )
    {
      if( s2.empty() )
      {
        while( !s1.empty() )
        {
          s2.push( s1.top() );
          s1.pop();
        }
      }
      s2.pop();
    }
    else 
    {
      if( s2.empty() )
      { 
        while( !s1.empty() )
        {
          s2.push( s1.top() );
          s1.pop();
        }
      }
      cout << s2.top() << '\n';
    }
  }
  return 0;
}
