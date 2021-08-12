#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF_PLUS= 1LL<<60;
const ll DP_TABLE= 100010;

template<class T> inline bool changemin(T &x,T y){
    bool result = false;
    if(y < x){
        x = y;
        result = true;
    }
    return result;
}

ll resolve(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll goal;
    cin >> goal;
    vector<ll> dp(DP_TABLE);
    vector<ll> higher(DP_TABLE);
    for(auto &e: dp){
        e = INF_PLUS;
    }
    for(auto &e: higher){
        cin >> e;
    }
    dp[0] = 0;
    for(ll j=0;j<goal;j++){
        changemin(dp[j+1],dp[j]+abs(higher[j]-higher[j+1]));
        changemin(dp[j+2],dp[j]+abs(higher[j]-higher[j+2]));
    }
    return dp[goal-1];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll testcase = 1;
    for (ll j = 0; j < testcase; j++)
    {
        cout  << resolve() << "\n";
    }
        
    return 0;
}
