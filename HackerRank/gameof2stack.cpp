#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int g;
  cin >> g;
  while( g-- )
  {
    int n, m, x;
    cin >> n >> m >> x;
    int a1[n], a2[m];

    // input is in reverse for stack, so store it in array and push it in reverse
    for( int i= 0; i< n; i++ )
      cin >> a1[i];
    for( int i= 0; i< m; i++ )
      cin >> a2[i];
    
    int i = 0, j = 0, count = 0, sum = 0;

    // get max sum from 1st list
    while( i < n && sum + a1[i] <= x )
    {
      sum += a1[i];
      i++;
    }
    
    count = i;

    // calculate max count by removing each an element of a1[i] from sum and check with a2[j]
    while( j < m && i >= 0 )
    {
      sum += a2[j];
      j++;
      while( sum > x && i > 0 )
      {
        i--;
        sum -= a1[i];
      }
      if( i+j > count && sum <= x )
        count = i + j;
    }

    cout << count << '\n';
      
  }
  return 0;
}
