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

vector<vector<int>> dp(110,vector<int>(100100,0));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showDP(int N,int W){
    for(int j=1;j<=N;j=j+1){
        for(int k=1;k<=W;k=k+1){
            debug("%3d",dp[j][k]);
        }
        debug("\n");
    }
    debug("\n");
}
int main(void){
    initial();
    int N,W;
    cin >> N >> W;
    vector<int> v(110,0);
    vector<int> w(110,0);
    for(int j=1;j<=N;j=j+1){
        cin >> v[j] >> w[j];
    }
    for(int j=1;j<=N;j=j+1){
        for(int k=1;k<=W;k=k+1){
            // jを選択しない
            dp[j][k]=dp[j-1][k];
            if(w[j]<=k){
                int first = dp[j-1][k];
                int second = dp[j][k-w[j]]+v[j];
                if(first<=second){
                    dp[j][k]=second;
                }
            }
        }
        showDP(N,W);
    }
    cout << dp[N][W] << "\n" << flush;

    return 0;
}
