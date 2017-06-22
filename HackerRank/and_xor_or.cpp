#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int *a = new int[n];
  for(int i= 0; i< n; i++)
    cin >> a[i];
  int max = 0;
  stack<int> s;

  for(int i= 0; i< n; i++)
  {
    while( !s.empty() )
    {
      int temp = s.top() ^ a[i];
      if( temp > max )
        max = temp;
      if( a[i] < s.top() )
        s.pop();
      else break;
    }
    s.push( a[i] );
  }

  cout << max << '\n';

  delete [] a;
  return 0;
}

  /*
   * original code
  for(int i= 1; i< n; i++)
  {
    int temp = 0;
    if( a[i-1] == s.top() )
    {
      temp = s.top() ^ a[i];
      if( s.top() > a[i] )
      {
        s.pop();
        s.push( a[i] );
      }
    }
    else 
    {
      // cout << "else jumla \n";
      int t1 = a[i-1] ^ a[i];
      // cout << a[i-1] << "  ^  " << a[i] << " = \t" << t1 << '\n';
      int t2 = 0;
      if( a[i] < s.top() )
      {
        t2 = s.top() ^ a[i];
        // cout << s.top() << "  ^  " << a[i] << " = \t" << t2 << '\n';
        s.pop();
        s.push( a[i] );
      }
      temp = t1 > t2 ? t1 : t2;
      // cout << "temp = \t" << temp;
      // cout << "else ends \n";
    }
    if( temp > max )
      max = temp;
    // cout << max << "\n";
  } 
  cout << max;
  delete [] a;
  return 0;
  
}*/
