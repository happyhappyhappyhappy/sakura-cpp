#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool solver(ll n,vector<ll> &X){
    if(n%2==1){
        return false;
    }
    X[0] = n/2;
    X[1] = 0;
    X[2] = 0;
    return true;
}
int main(void){ 
    initial();
    int testcase=0;
    cin >> testcase;
    for(int j=0;j<testcase;j++){
        vector<ll> X(3,0);
        ll sum;
        bool ok;
        cin >> sum;
        ok = solver(sum,X);
        if (ok) {
            cout << X[0] << " " << X[1] << " " 
            << X[2] << "\n" << flush;
        }
        else{
            cout << "-1\n" << flush; 
        }
    }
    return 0;
}
