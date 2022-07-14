#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){ 
    initial();
    int testcase=0;
    cin >> testcase;
    while(--testcase){
        vector<ll> X(3,0);
        ll sum;
        bool ok;
        cin >> sum;
        ok = solver(sum,X);
        if(ok){
            // cout TODO: ここから
        }
    }
    return 0;
}
