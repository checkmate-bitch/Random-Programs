#include <iostream>
#include <climits>

#define min(a,b) ( a < b ? a : b )

using namespace std;

int main()
{
  // bottom up
  int max = 21;
  int table[max];

  for(int i= 0; i< max; i++)
    table[i] = -1;
  table[0] = 0, table[1] = 1, table[2] = 2, table[3] = 3;
  for(int i= 2; i< max; i++)
  {
    if( table[i] == -1 || ( table[i-1] + 1 ) < table[i] )
    {
      table[i] = table[i-1] + 1;
    }
    for(int j= 2; i*j < max && j <= i; j++)
    {
      if( table[i*j] == -1 || ( table[i] + 1 ) < table[i*j] )
      {
        table[i*j] = table[i] + 1;
      }
    }
  }
  /*
  cout << endl;
  for(int i= 0; i< max; i++)
    cout << "table[" << i << "] : " << table[i] << endl;
  */

  int q;
  cin >> q;
  while( q-- )
  {
    int n;
    cin >> n;
    cout << table[n] << endl;
  }

  return 0;
}
/*
 * original code 
 * top-down 
 * even with memoization I could not get it to work under required time constraints
 * so switching to a bottom up approach
 *
int down_to_zero( int n )
{
  if( n == 0 )
    return 0;
  int a = INT_MAX;
  for(int i = 2; i*i <= n; i++)
  {
    if( n % i == 0 )
    {
      a = min( 1 + down_to_zero( n / i ), a );
    }
  }
  it b = 1 + down_to_zero( n-1 );
  return min(a,b);
}

int main()
{
  int q;
  cin >> q;
  while( q-- )
  {
    int n;
    cin >> n;
    cout << down_to_zero( n ) << '\n';
  }
  return 0;
}

*/
