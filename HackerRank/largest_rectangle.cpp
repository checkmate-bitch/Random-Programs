#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int height[n], area[n];
  for(int i= 0; i< n; i++)
    cin >> height[i];
  for(int i= 0; i< n; i++)
  {
    int h = height[i];  // height of i+1th building
    int k = 0;
    for(int j= i; j < n; j++)
    {
      if(height[j] >= h)
        k++;
      else break;
    }
    for(int j= i-1; j >= 0; j--)
    {
      if( height[j] >= h )
        k++;
      else break;
    }
    area[i] = h * k;
  }

  int max = area[0];
  for(int i= 1; i< n; i++)
  {
    if( area[i] > max )
      max = area[i];
  }

  cout << max;

  return 0;
}
