#include<bits/stdc++.h>
// 参考文献と自分オリジナルの掛け合わせ
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
const int INF=10001;
const int N_MAX=50001;
const int M_MAX=21;
vector<vector<int>> dp(M_MAX,vector<int>(N_MAX,0));
int N,M;
vector<int> c(M_MAX,0);
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showDP(){
    for(int m=1;m<=M;m=m+1){
        for(int n=1;n<=N;n=n+1){
            if(dp[m][n]==INF){
                debug(" INF");
            }
            else{
                debug(" %3d",dp[m][n]);
            }
        }
        debug("\n");
    }
    debug("\n");
}
int min_coin(void){
    for(int n=0;n<=N;n=n+1){
        dp[0][n]=INF;
    }
    for(int m=0;m<=M;m=m+1){
        dp[m][0]=0;
    }
    for(int m=1;m<=M;m=m+1){
        for(int n=1;n<=N;n=n+1){
            if(n-c[m]<0){
                dp[m][n]=dp[m-1][n];
                continue;
            }
            dp[m][n]=min(dp[m-1][n],dp[m][n-c[m]]+1);
        }
        showDP();
    }
    return dp[M][N];
}
int main(void){
    initial();

    cin >> N >> M;
    for(int j=1;j<=M;j=j+1){
        cin >> c[j];
    }
    cout << min_coin() << "\n" << flush;
    return 0;
}
