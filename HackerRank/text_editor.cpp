#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
  int q;
  string s;
  stack<string> plates;
  cin >> q;
  while ( q-- )
  {
    int type;
    cin >> type;
    
    // insert string
    if( type == 1 )
    {
      string str;
      cin >> str;
      plates.push(s);
      s += str;
    }

    // delete last k characters of string
    else if ( type == 2  && !s.empty() )
    {
      int k;
      cin >> k;
      plates.push(s);
      s.erase( s.size() - k );
    }

    // print kth character of string
    else if ( type == 3 && !s.empty() )
    {
      int k;
      cin >> k;
      cout << s.at(k - 1) << endl;
    }

    // undo
    else{
      s = plates.top();
      plates.pop();
    }
  }

  return 0;
}
