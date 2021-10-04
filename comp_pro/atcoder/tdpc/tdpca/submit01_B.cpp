#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// グローバル変数
ll MAXN = 100*2;
ll MAXCOUNT = MAXN*(100*2);
vector<ll> point(MAXN);
vector<vector<bool>> dp(MAXN,vector<bool>(MAXCOUNT));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);
    for(ll j=0;j<MAXN;j=j+1){
        for(ll k=0;k<MAXCOUNT;k=k+1){
            dp[j][k] = false;
        }
    }
//    dp[0][0]=true;
}

int main(void){
    ll N;
    cin >> N;
    for(ll j=0;j<MAXN;j=j+1){
        cin >> point[j];
    }
    // dpの本領発進
    dp[0][0] = true;
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
    ll topans=0;
    for(ll j=0;j<N;j++){
        topans = point[j];
    }
    for(ll j=0;j<N+1;j++){
        for(ll k=0;k <= topans;k++){
            char output;
            if(dp[j][k]){
                output='o';
            }
            else{
                output='x';
            }
            cout << output << " ";
        }
        cout << "\n";
    }
    return 0;
}