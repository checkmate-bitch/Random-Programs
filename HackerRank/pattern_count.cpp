#include <iostream>
#include <string>

using namespace std;

int main()
{
  int q;
  cin >> q;
  while( q-- )
  {
    int count = 0;
    string str;
    cin >> str;
    for(int i= 0; i< str.length(); i++)
    {
      bool flag = false;
      if( str[i] == '1' )
      {
        for(int j= i+1; str[j] != '1'; j++)
        {
          if( str[j] == '0' )
            flag = true;
          else
          {
            flag = false;
          }
          i = j;
          if( !flag )
            break;
        }
        if( flag )
          count++;
      }
    }
    cout << count << '\n';
  }
  return 0;
}
