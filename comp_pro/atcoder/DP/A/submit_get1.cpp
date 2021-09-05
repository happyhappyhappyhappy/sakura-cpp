#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

template<class XXX> inline bool minchange(XXX &a,XXX b){
    bool result = false;
    if(b < a){
        a = b;
        result = true;
    }
    return result;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const ll DP_TABLE=100010;
    const ll INF_PLUS=1LL<<60;
    ll point;
    cin >> point;
    vector<ll> dp(DP_TABLE);
    vector<ll> height(DP_TABLE);
    for(auto &e:height){
        cin >> e;
    }
    for(auto &e:dp){
        e = INF_PLUS;
    }
    /** for(ll j=0;j<point;j++){
        cout << height[j] << "\t";
    }
    cout << "\n"; **/  
    dp.at(0) = 0; 
    for(ll j=1;j < point ;j=j+1){
        minchange(dp[j],dp[j-1]+abs(height[j-1]-height[j]));
        if(j > 1){
            minchange(dp[j],dp[j-2]+abs(height[j-2]-height[j]));
        }
    }
    cout << dp[point-1] << "\n";
    return 0;
}