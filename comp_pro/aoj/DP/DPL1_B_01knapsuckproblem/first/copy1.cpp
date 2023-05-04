#include <iostream>
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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;

// 入力
int N;
int W, weight[110], value[110]; // 品物の個数は 100 個なので少し余裕持たせてサイズ 110 に

// DPテーブル
int dp[110][100100] = {0};
void showDP(int NX,int NW){
    for(int j=0;j<=NX;j=j+1){
        for(int k=0;k<=NW;k=k+1){
            debug(" %d",dp[j][k]);
        }
        debug("\n");
    }
    debug("\n");
}

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; ++i) cin >> value[i] >> weight[i];
    for(int j=0;j<N;j=j+1){
        debug("品物 %d: 重さ%d 価値%d\n",j,weight[j],value[j]);
    }
    // DPループ
    for (int i = 0; i < N; ++i) {
        for (int sum_w = 0; sum_w <= W; ++sum_w) {

            // i 番目の品物を選ぶ場合
            if (sum_w - weight[i] >= 0) {
                chmax(dp[i+1][sum_w], dp[i][sum_w - weight[i]] + value[i]);
            }

            // i 番目の品物を選ばない場合
            chmax(dp[i+1][sum_w], dp[i][sum_w]);
        }
        showDP(N,W);
    }

    // 最適値の出力
    cout << dp[N][W] << endl;
}
