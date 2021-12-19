#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

int main(void){
    int testcase=0;
    cin >> testcase;
    for(int j=0;j<testcase;j=j+1){
        vector<int> base_d(4);
        for(auto& e:base_d){
            cin >> e;
        }
        COUT(base_d[0]);
       // cout << base_d.size() << "\n" << flush;
    }
    return 0;
}