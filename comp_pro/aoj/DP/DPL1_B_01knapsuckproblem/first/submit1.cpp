#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;
template<class X> inline bool chmin(X& a,X b){
    if(b<a){
        a=b;
        return true;
    }
    return false;
}
template<class X> inline bool chmax(X& a,X b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showDP(vector<vector<int>>& dp,int N,int W){
    for(int j=0;j<=N;j=j+1){
        for(int k=0;k<=W;k=k+1){
            debug(" %3d",dp[j][k]);
        }
        debug("\n");
    }
    debug("\n");
}

int main(void){
    initial();
    int N,W;
    cin >> N >> W;
    vector<int> v(N,0);
    vector<int> w(N,0);
    vector<vector<int>> dp(110,vector<int>(10100,0));
    for(int j=0;j<N;j=j+1){
        cin >> v[j] >> w[j];
    }
    for(int j=0;j<N;j=j+1){
        for(int sum_kg=0;sum_kg<=W;sum_kg=sum_kg+1){
            // j番目の品物を選ぶ場合
            if(w[j]<=sum_kg){
                chmax(dp[j+1][sum_kg],dp[j][sum_kg-w[j]]+v[j]);
            }
            else{
                chmax(dp[j+1][sum_kg],dp[j][sum_kg]);
            }
        }
        showDP(dp,N,W);
    }
    cout << dp[N][W] << "\n" << flush;
    return 0;
}
