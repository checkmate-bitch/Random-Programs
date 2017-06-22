// ONP - Transform the Expression into Reverse Polish Notation

#include <iostream>
#include <string>

using namespace std;

void print( char a[], int size )
{
  cout<<"Stack\n";
  for( int i= 0; i< size; i++ )
    cout<<a[i]<<"\t";
  cout<<endl;
}

int main()
{
  int t;
  cin >> t;

  while( t-- )
  {
    string str, ans;
    char stack[400];
    for(int i= 0; i<= 400; i++)
      stack[i] = '\0';
    int top = 0;

    cin >> str;

    for( int i= 0; i< str.length(); i++ )
    {
      // cout<<"str["<<i<<"] is "<<str[i]<<endl;
      if( str[i] == '(' ){
        stack[top++] = str[i];
        // cout<<"In 1 \t"<<str[i]<<endl;
      }
      else if ( str[i] >= 97 && str[i] <= 122 ){
        ans = ans + str[i];
        // cout<<"In 2 \t"<<str[i]<<endl;
      }
      else if ( str[i] == ')' )
      {
        top = top - 1;
        /*if( i == str.length() - 1 )
          cout<<"In 3 \n";
        */
        while( stack[top] != '(' )
        {
          if( stack[top] == '/' || stack[top] == '^' || stack[top] == '*' || stack[top] == '+' || stack[top] == '-' )
            ans = ans + stack[top];
          top = top - 1;
        }
      }

      else  {
        stack[top++] = str[i];
        // cout<<"In 4 \t"<<str[i]<<endl;
      }

      //print(stack, top);
      //cout<<"answer \t"<<ans<<"\n\n";
    }

    cout<<ans<<endl;
  }

  return 0;

}

