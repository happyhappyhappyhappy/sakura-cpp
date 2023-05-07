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
const int INF=60000;

vector<vector<int>> dp(25,vector<int>(60000,0));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int sn=0;sn<60000;sn=sn+1){
        dp[0][sn]=INF;
    }
    for(int mc=0;mc<25;mc=mc+1){
        dp[mc][0]=0;
    }
}
void showDP(int X,int Y){
    for(int j=1;j<=X;j=j+1)
    {
        debug(" +%3d :",j);
        for(int k=1;k<=Y;k=k+1){
            if(dp[j][k]==INF){
                debug(" INF");
            }
            else{
                debug(" %3d",dp[j][k]);
            }
        }
        debug("\n");
    }
    debug("\n");
}
int main(void){
    initial();
    int MC,SN;
    cin >> SN >> MC;
    vector<int> coin(25,0);
    for(int j=1;j<=MC;j=j+1){
        cin >> coin[j];
    }
    for(int j=1;j<=MC;j=j+1){
        for(int k=1;k<=SN;k=k+1){
            if(k-coin[j]<0){
                // 今の金額においてコインが使えない場合
                dp[j][k]=dp[j-1][k];
                continue;
            }
            // 使える条件ならば、あえて使わないor使った場合で小さい方を使う
            dp[j][k]=min(dp[j-1][k],dp[j][k-coin[j]]+1);
        }
        showDP(MC,SN);
    }
    cout << dp[MC][SN] << "\n" << flush;
    return 0;
}
