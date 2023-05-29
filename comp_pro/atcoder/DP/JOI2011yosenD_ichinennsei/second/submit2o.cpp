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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showValue(vector<vector<ll>> &DP){
    int H=(int)DP.size();
    int W=(int)DP[0].size();
    for(int h=0;h<H;h=h+1){
        debug(" %3d 個目: ",h+1);
        for(int w=0;w<W;w=w+1){
            debug(" %3lld",DP[h][w]);
        }
        debug("\n");
    }
}


int main(void){
    initial();
    int Xall=0;// 取り得る全部の値
    cin >> Xall;
    int X=Xall-1; // 足し引きする合計数
    vector<ll> V(X,0); // 足し引き要素
    int R=0; // 確認する結果
    for(int j=0;j<X;j=j+1){
        cin >> V[j];
    }
    cin >> R;
    vector<vector<ll>> DP(X,vector<ll>(21,0LL));// 結果には20も入るので
    DP[0][V[0]]=1LL;
    for(int j=0;j<X-1;j=j+1){
       for(int k=0;k<=20;k=k+1){
            int next_plus=k+V[j+1];
            int next_minus=k-V[j+1];
            if(next_plus<=20){
                DP[j+1][next_plus]=DP[j+1][next_plus]+DP[j][k];
            }
            if(0<=next_minus){
                DP[j+1][next_minus]=DP[j+1][next_minus]+DP[j][k];
            }
       }
    }
    showValue(DP);
    cout << DP[X-1][R] << "\n" << flush;
    return 0;
}
