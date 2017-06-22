#include <iostream>

using namespace std;

long long int max_coins( long long int no, long long int arr[] )
{
  if( arr[no] > 0 )
    return arr[no];
  
  if( no == 0 )
    return 0;

  long long int a = max_coins ( no/4, arr ); 
  long long int b = max_coins ( no/3, arr ); 
  long long int c = max_coins ( no/2, arr ); 

  if( no < a+b+c )
    arr[no] = a+b+c;
  else arr[no] = no;

}

int main()
{
  int t;
  cin >> t;
  long long int arr[1000];
  for( int i= 0; i< 1000; i++ )
    arr[i] = 0;
  arr[1] = 1;
  while( t-- )
  {
    long long int no;
    cin >> no;
    cout << max_coins( no, arr ) << endl;
  }
  return 0;
}
