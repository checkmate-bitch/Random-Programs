#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int* a = new int[2*n];
  for(int i= 0; i< 2*n; i+= 2)
    cin >> a[i] >> a[i+1];
  // stores difference between amount of petrol and distance to next petrol pump
  int* diff = new int[n];
  // stores the differences that are positive
  stack<int> s;
  for(int i= 2*n - 2; i>= 0; i-= 2)
  {
    diff[i/2] = a[i] - a[i+1];
    if( diff[i/2] >= 0 )
    {
      s.push( i/2 );
    }
  }
  // store index till each element can go & if fail what was the difference
  int store[s.size()][2];
  while( !s.empty() )
  {
    int index = s.top();
    s.pop();
    // cout << diff[index] << '\n';
    int i = index+1 >= n ? 0 : index + 1;
    bool flag = true;
    int can_travel_next = diff[index];
    for(; i < n; i++)
    {
      can_travel_next += diff[i];
      if( can_travel_next < 0 )
      {
        // store[k][0] = i;
        // store[k++][1] = can_travel_next;
        flag = false;
        break;
      }
    } 
    if( flag && index + 1 != n )
    {
      for(i= 0; i < diff[index]; i++)
      {
        can_travel_next += diff[i];
        if( can_travel_next < 0 )
        {
          // store[k][0] = i;
          // store[k++][1] = can_travel_next;
          flag = false;
          break;
        }
      }
    }
    if( flag )
    {
      cout << index;
      break;
    }
  }

  delete [] a;
  delete [] diff;
  return 0;
}
