#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

int main(void){
    vector<int> x(10);
    for(int j=0;j<10;j++){
        x[j] = j+1;
    }
    for(int j=0;j<x.size();j=j+1){
        cout << x[j] << " ";
    }
    cout << "\n" << flush;
    x.push_back(0);
    sort(x.begin(),x.end());
    for(int j=0;j<x.size();j++){
        cout << x[j] << " ";
    }
    cout << "\n" << flush;
    return 0;
}