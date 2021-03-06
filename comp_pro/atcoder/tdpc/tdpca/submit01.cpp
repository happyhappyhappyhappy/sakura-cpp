#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
// 本番用


// グローバル変数
ll MAXN = 100*2;
ll MAXCOUNT = MAXN*(100*2);
vector<ll> point(MAXN);
vector<vector<bool>> dp(MAXN,vector<bool>(MAXCOUNT,false));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dp[0][0]=true;
}

int main(void){
    initial();
    ll N;
    cin >> N;
    for(ll j=0;j<MAXN;j=j+1){
        cin >> point[j];
    }
    // dpの本領発進
    for(ll j=0;j<N;j=j+1){
        for(ll k=0;k<MAXCOUNT;k=k+1){
            if(dp[j][k] != true){
                continue; // 処理しない
            }
            dp[j+1][k] = dp[j][k];
            if(k+point[j] <= MAXCOUNT){
                dp[j+1][k+point[j]]=true;
            }
        }
    }
    ll answer = 0;
    for(ll j=0;j<MAXCOUNT;j=j+1){
        if(dp[N][j] == true){
            answer = answer + 1;
        }
    }
    cout << answer << "\n";
}