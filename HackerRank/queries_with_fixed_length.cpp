#include <iostream>
#include <deque>

using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  int a[n];
  for(int i= 0; i< n; i++)
    cin >> a[i];
  while( q-- )
  {
    int d;
    cin >> d;
    deque<int> q(d);
  }

  return 0;
}
 

  /*
   * original code
   * O(n*d) complexity
   * will not pass all test cases 
 {
    if( d == 1 )
    {
      int min = a[0];
      for(int i= 1; i< n; i++)
        if( a[i] < min )
          min = a[i];
      cout << min << '\n';
    }
    else
    {
      queue<int> q;
      for(int i= 0; i<= n - d; i++)
      {
        int max = a[i];
        for(int j= i+1; j< i+d; j++)
        {
          if( a[j] > max )
            max = a[j];
        }
        q.push(max);
      }
      int min = q.front();
      q.pop();
      while( !q.empty() )
      {
        if( q.front() < min )
          min = q.front();
        q.pop();
      }
      cout << min << '\n';
    }
  }
  
  return 0;
}
*/
