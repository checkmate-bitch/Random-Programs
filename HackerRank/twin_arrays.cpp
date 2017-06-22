#include <iostream>

using namespace std;

int get_min( int a[], int size )
{
  int min = a[0], index = 0;
  for(int i= 1; i< size; i++)
  {
    if( a[i] < min )
    {
      min = a[i];
      index = i;
    }
  }
  return index;
}

int get_next_min( int a[], int size, int min_index )
{
  int index = 0, next_min = a[0];
  for(int i= 1; i< size; i++)
  {
    if( a[i] < next_min && i != min_index )
    {
      index = i;
      next_min = a[i];
    }
  }
  return index;
}

int main()
{
  int n;
  cin >> n;
  int *a = new int[n];
  int *b = new int[n];
  for(int i= 0; i< n; i++)
    cin >> a[i];
  for(int i= 0; i< n; i++)
    cin >> b[i];
  int min_index_a = get_min(a, n);
  int min_index_b = get_min(b, n);
  if( min_index_a != min_index_b )
    cout << a[min_index_a] + b[min_index_b];
  else
  {
    int next_min_a = get_next_min(a, n, min_index_a);
    int next_min_b = get_next_min(b, n, min_index_b);
    int min = a[next_min_a] + b[min_index_b] < a[min_index_a] + b[next_min_b] 
              ? a[next_min_a] + b[min_index_b]
              : a[min_index_a] + b[next_min_b];
    cout << min;
  }
  return 0;
}
