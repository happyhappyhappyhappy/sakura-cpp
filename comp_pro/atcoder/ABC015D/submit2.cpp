#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

template<class XXX> void chmax(XXX& x,XXX y){
    if(x < y){
        x = y;
    }
}
template<class XXX> bool p_chk(XXX& x){
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
const int M_INF=-(1<<29); // 極最小値(マイナス無限大を設定)
// 大域変数
int N; // 最大スクリーンショット数
int W; // 最大広さ
int K; // 設定可能スクリーンショット数
// 大域配列 : 固定数でなければいけない
int width[MAX_SHOT]; // 各スクリーンショットの広さ
int imp[MAX_SHOT]; // 各スクリーンショットの重要性
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
    cin >> W; // 最大幅
    cin >> N >> K; // 持っているスクリーンショットの数⇒貼れる数
    // スクショデータの読み込み
    for(int shot=0;shot < N;shot=shot+1){
    cin >> width[shot] >> imp[shot];
    }
    // DP処理開始
    // COUT(N);
    for(int nShot=0;nShot < N;nShot++) // 入れようかどうか迷っているショット
    {   
        // COUT(nShot);
        for(int cShot=0;cShot < N;cShot++) // 入れたショット数
        {
           //  COUT(cShot);
            for(int used_width=0;used_width <= W;used_width++) // 利用済みの幅
            {
                // 貼ることが出来る場合
                // COUT(nShot);
                // COUT(cShot);
                // COUT(used_width);
                
                if(cShot+1<=K){
                    if(used_width+width[nShot]<= W){
                    chmax(DP[nShot+1][cShot+1][used_width+width[nShot]],
                        DP[nShot][cShot][used_width]+imp[nShot]);
                        }
                    }
                // 貼らない場合
                chmax(DP[nShot+1][cShot][used_width],DP[nShot][cShot][used_width]);
            }
        }
    }
    int answer = 0; // 回答の下限
    for(int used_shot=0;used_shot < MAX_SHOT;used_shot++){
        for(int used_width=0;used_width<MAX_WIDTH;used_width++){
            chmax(answer,DP[N][used_shot][used_width]);
        }
    }
    cout << answer << "\n" << flush;
    return 0;
}
