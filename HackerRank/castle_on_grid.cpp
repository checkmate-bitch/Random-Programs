#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

class coord
{
  public:
  int x, y;
  int count , dir;
  coord()
  {
    x = 0, y = 0, count = 0, dir = 0;
  }
  coord(int a, int b, int num, int direction)
  {
    x = a;
    y = b;
    count = num;
    dir = direction;
  }
};

int main()
{
  int n;
  cin >> n;
  char grid[n][n];
  bool z[n][n];
  for(int i= 0; i< n; i++)
    for(int j= 0; j< n; j++)
    {
      cin >> grid[i][j];
      z[i][j] = true;
    }
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  queue<coord> q;
  queue<int> steps;
  q.push(coord(a , b, 0, 0));
  while( !q.empty() )
  {
    coord temp = q.front();
    q.pop();
    int x = temp.x, y = temp.y, count = temp.count, dir = temp.dir;

    // get all neighbors of x,y

    // up
    if( !( dir == 1 || dir == 3 ) )
    {
      for(int i= x-1; i >= 0; i--)
      {
        if( grid[i][y] == 'X' )
          break;
        if( z[i][y] )
        {
          q.push( coord(i, y, count+1, 1) );
          z[i][y] = false;
        }
        if( i == c && y == d )
        {
          steps.push(count+1);
        }
      }
    }

    //down
    if( !( dir == 1 || dir == 3 ) )
    {
      for(int i= x+1; i < n; i++)
      {
        if( grid[i][y] == 'X' )
          break;
        if( z[i][y] )
        {
          q.push( coord(i, y, count+1, 3) );
          z[i][y] = false;
        }
        if( i == c && y == d )
        {
          steps.push(count+1);
        }
      }
    }

    // left
    if( !( dir == 2 || dir == 4 ) )
    {
      for(int i= y-1; i >= 0; i--)
      {
        if( grid[x][i] == 'X' )
          break;
        if( z[x][i] )
        {
          q.push( coord(x, i, count+1, 4) );
          z[i][y] = false;
        }
        if( x == c && i == d )
        {
          steps.push(count+1);
        }
      }
    }
    
    // right
    if( !( dir == 2 || dir == 4 ) )
    {
      for(int i= y+1; i < n; i++)
      {
        if( grid[x][i] == 'X' )
          break;
        if( z[x][i] )
        {
          q.push( coord(x, i, count+1, 2) );
          z[i][y] = false;
        }
        if( x == c && i == d )
        {
          steps.push(count+1);
        }
      }
    }
  }
  int min = steps.front();
  steps.pop();
  for(int i= 0; i< steps.size(); i++)
  {
    if( steps.front() < min )
      min = steps.front();
    steps.pop();
  }
  cout << min;
  return 0;
}
