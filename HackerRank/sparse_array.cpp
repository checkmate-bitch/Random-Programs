#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    string str[10000], queries[10000];
    int i = 0;
    cin>>n;
    int n_temp = n;
    while(n_temp-- > 0){
        cin>>str[i++];
    }
    i = 0;
    cin>>q;
    int q_temp = q;
    while(q_temp-- > 0){
        cin>>queries[i++];
    }
    i = 0;

    while(i < q){
        int count = 0;
        for(int j= 0; j< n; j++){
            //cout<<"\n"<<queries[i]<<".compare("<<str[j]<<")\t="<<queries[i].compare(str[j])<<endl;
            if( queries[i].compare( str[j] ) == 0 ){
                count++;
            }
        }
        cout<<count;
        i++;
    }
    return 0;
}
