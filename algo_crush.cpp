#include <iostream>

using namespace std;

void getMax(int list[], int n){
  int max = list[0];
  for(int i= 0; i< n; i++){
    if( list[i] > max ){
      max = list[i];
    }
  }
  cout<<max<<endl;
}

void printList(int list[], int n){
  for(int i= 0; i< n; i++){
    cout<<list[i]<<"\t";
  }
  cout<<endl;
}

int main(){
  int n, m, a, b, k;
  cin>>n>>m;
  int list[n];
  for(int i= 0; i< n; i++)
   list[i] = 0; 
  for(int i= 0; i< m; i++){
    cin>>a>>b>>k;
    for(int j= a - 1; j<= b - 1; j++){
      list[j] += k;
    }
    // printList(list, n);
  }
  getMax(list, n);
  return 0;
}
