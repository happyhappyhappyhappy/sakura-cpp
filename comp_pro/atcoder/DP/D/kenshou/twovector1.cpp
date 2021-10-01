#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void){

    vector<vector<ll>> dp(10,vector<ll>(15,-1));
    for(ll j=0; j < 10 ; j=j+1){
        for(ll k=0; k < 15; k=k+1){
            cout << dp[j][k] << " ";
        }
        cout << "\n";
    }
    return 10;   
}