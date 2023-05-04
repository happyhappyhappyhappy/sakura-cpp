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
template<class XXX> bool chmax(XXX& a,XXX b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

vector<vector<int>> dp(110,vector<int>(100100,0));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showDP(int N,int W){
    for(int j=0;j<=N;j=j+1){
        for(int k=0;k<=W;k=k+1){
            debug(" %2d",dp[j][k]);
        }
        debug("\n");
    }
    debug("\n");
}

int main(void){
    initial();
    int N,W;
    vector<int> value(N,0);
    vector<int> weight(N,0);
    cin >>N >> W;
    for(int j=0;j<N;j=j+1){
        cin >> value[j] >> weight[j];
    }
    for(int j=0;j<N;j=j+1){
        for(int sum_w=0;sum_w<=W;sum_w=sum_w+1){
            if(weight[j]<=sum_w){ // 入れるとき
                chmax(dp[j+1][sum_w],
                dp[j][sum_w-weight[j]]+value[j]);
            }
            // 入れないとき
            chmax(dp[j+1][sum_w],dp[j][sum_w]);
        }
        showDP(N,W);
    }
    cout << dp[N][W] << "\n" << flush;
    return 0;
}
