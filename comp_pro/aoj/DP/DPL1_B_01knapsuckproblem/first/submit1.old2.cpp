#include<bits/stdc++.h>
using namespace std;
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
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;
template<class X> bool chmin(X &a,X b){
    bool res=false;
    if(a>b){
        a=b;
        res=true;
    }
    return res;
}
template<class X> bool chmax(X &a,X b){
    bool res=false;
    if(a<b){
        a=b;
        res=true;
    }
    return res;
}
int dp[110][100100]={0};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showDP(int N,int W){
    for(int j=0;j<=N;j=j+1){
        for(int k=0;k<=W;k=k+1){
            debug(" %d",dp[j][k]);
        }
        debug("\n");
    }
    debug("\n");
}

int main(void){
    initial();
    int N,W;
    cin >> N >> W;
    vector<int> value(N,0);
    vector<int> weight(N,0);
    for(int j=0;j<N;j=j+1){
        cin >> value[j] >> weight[j];
    }
    for(int j=0;j<N;j=j+1){
        debug("品物 %d: 重さ%d 価値%d\n",j,weight[j],value[j]);
    }
    debug("\n");
    for(int j=0;j<N;j=j+1){
        for(int sum_w=0;sum_w<=W;++sum_w)
        {
            if(sum_w-weight[j]>=0){
                debug("%d番目の合計%dで 重さ%d入れるか変換検討します\n",j,sum_w,weight[j]);
                debug("chmax([%d+1][%d],[%d][%d-%d]+%d)\n",
                j,sum_w,j,sum_w,weight[j],value[j]);
                chmax(dp[j+1][sum_w],dp[j][sum_w-weight[j]]+value[j]);
            }
            chmax(dp[j+1][sum_w],dp[j][sum_w]);
        }
        // for(int sum_weight=0;sum_weight<=W;sum_weight=sum_weight+1){
        //     if(0<=sum_weight-weight[j]){
        //         chmax(dp[j+1][sum_weight],
        //         dp[j][sum_weight-weight[j]]+value[j]);
        //     }
        //     else{
        //         chmax(dp[j+1][sum_weight],dp[j][sum_weight]);
        //     }
        // }
        showDP(N,W);
    }
    cout << dp[N][W] << "\n" << flush;
    return 0;
}
