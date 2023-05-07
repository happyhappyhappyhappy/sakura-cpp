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
// const int yamaMAX_INT = 1 << 29;
const int yamaMAX_INT = 70000;
const ll yamaMAX_LL = 1LL << 58;
template<class XXX> bool chmin(XXX &a,XXX b){
    if(b<a){
        a=b;
        return true;
    }
    return false;
}
vector<vector<int>> dp(30,vector<int>(50500));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showDP(int K,int S){
    for(int k=1;k<=K;k=k+1){
        for(int s=1;s<=S;s=s+1){
            if(dp[k][s]==yamaMAX_INT){
                debug(" INF");
            }
            else{
                debug(" %3d",dp[k][s]);
            }
        }
        debug("\n");
    }
    debug("\n");
}
int main(void){
    initial();
    int S,K;
    cin >> S >> K;
    vector<int> C(30,0);
    for(int j=1;j<=K;j=j+1){
        cin >> C[j];
    }
    for(int j=0;j<=S;j=j+1){
        dp[0][S]=yamaMAX_INT;
    }
    for(int j=0;j<=K;j=j+1){
        dp[j][0]=0;
    }
    for(int j=1;j<=K;j=j+1){
        for(int k=1;k<=S;k=k+1){
            if(0<=(k-C[j])){
                dp[j][k]=min(dp[j-1][k],dp[j][k-C[j]]+1);
            }
            chmin(dp[j][k],dp[j-1][k]);
        }
        showDP(K,S);
    }
    cout << dp[K][S] << "\n" << flush;
    return 0;
}
