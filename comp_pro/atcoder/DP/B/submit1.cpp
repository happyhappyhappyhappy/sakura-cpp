#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1LL << 62;

template<class XXX> inline bool minchange(XXX &a,XXX b){
    if( b < a){
        a = b;
        return true;
    }
    return false;
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}

int main(void){
    int N,K;
    cin >> N >> K;
    vector<int> h(N);
    for(auto &e:h){
        cin >> e;
    }
    // for(auto &e:h){
    //     cout << e << " ";
    // }
    // cout << "\n";
    vector<ll> dp(N+K+1);
    for(auto &e:dp){
        e = INF;
    }
    dp[0] = 0;
    for(int j=0;j < N+1;j=j+1){
        for(int m=0; m < K ; m = m + 1){
            int cost=1;

        }
    }
}