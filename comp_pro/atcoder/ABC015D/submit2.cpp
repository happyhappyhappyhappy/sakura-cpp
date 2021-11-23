#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<

template<class XXX> inline void chmax(XXX& x,XXX y){
    if(x < y){
        x = y;
    }
}
template<class XXX> inline bool p_chk(XXX& x){
    if(x >= 0){
        return true;
    }
    else{
        return false;
    }
}
// 大域変数固定値
const int MAX_WIDTH=10100; // 最大の広さ
const int MAX_SHOT=55; // スクリーンショットの最大数
const int M_INF=-(1<<29) // 極最小値(マイナス無限大を設定)
// 大域変数
int N; // 最大スクリーンショット数
int W; // 最大広さ
int K; // 設定可能スクリーンショット数
// 大域配列 : 固定数でなければいけない
int width[N]; // 各スクリーンショットの広さ
int imp[N]; // 各スクリーンショットの重要性
int DP[MAX_SHOT][MAX_SHOT][MAX_WIDTH];
// スクリーンショット→利用可能スクリーンショット→最大広さ

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // DP初期化
    for(int j=0;j<MAX_SHOT;j++){
        for(int k=0;k<MAX_SHOT;k++){
            for(int m=0;m<MAX_WIDTH;m++){
                DP[j][k][m]=M_INF;
            }
        }
    }
    DP[0][0][0]=0;// ここだけ例外 
}

int main(void){
initial();
// 問題のデータ書き込み
// 各スクショの情報
return 0;
}
