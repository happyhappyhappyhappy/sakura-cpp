#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

int main(void){
    int testcase;
    int element;
    cin >> element >> testcase;
    cout << element << "\n" << flush;
    for(int j=0;j<testcase;j=j+1){
        vector<int> X(element);
        for(int k=0;k<element;k=k+1){
            cin >> X[k];
        }
        sort(X.begin(),X.end());
        for(int k=0;k<element;k=k+1){
            cout << X[k] << " ";
        }
        cout << "\n" << flush;
    }
    return 0;
}