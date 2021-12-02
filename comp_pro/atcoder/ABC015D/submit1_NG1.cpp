#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
// DP用大きさチェッカー
template<class XXX> inline void chmax(XXX& x,XXX y){
    if(x<y){
        x=y;
    }
}

// 大域固定変数
const int MAX_WIDTH=10100; // 用紙幅
const int MAX_SHOT=55;
// 入力値単体
int N; // 取ったスクリーンショットの数
int W; // 貼れる写真の幅
int K; // 貼れるスクリーンショットの数
// 入力値配列
int width[MAX_SHOT]; // 幅
int important[MAX_SHOT]; // 重要度
// DP
int DP[MAX_SHOT][MAX_SHOT][MAX_WIDTH]; // 中身は重要度

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int j=0;j<MAX_SHOT;j++){
        for(int k=0;k<MAX_SHOT;j++){
            for(int m=0;m<MAX_WIDTH;m++){
                DP[j][k][m]=-1;
            }
        }
    }
    DP[0][0][0]=0;
}

int main(void){
    cin >> W;
    cin >> N >> K;
    for(int shot=0;shot<N;shot++){
        cin >> width[shot] >> important[shot];
    }    
    for(int a_shot=0;a_shot<N;a_shot++)
    { // all shot
        for(int n_shot=0;n_shot<N;n_shot++)
        { // now shot
            for(int n_width=0;n_width<W;n_width++)
            {
                if( n_shot+1 <= K && n_width+width[a_shot] <= W) 
                // 追加可能の場合
                {
                    chmax(DP[a_shot+1][n_shot+1][n_width+width[a_shot]],
                    DP[a_shot][n_shot][n_width]+important[a_shot]);
                }
            // 追加しない、もしくは出来ない場合
                chmax(DP[a_shot+1][n_shot][n_width],
                DP[a_shot][n_shot][n_width]);
                

            }
        }
    }
    int answer=0;
    for(int n_shot=0;n_shot<MAX_SHOT;n_shot++){
        for(int n_width=0;n_width<MAX_WIDTH;n_width++){
            chmax(answer,DP[N][n_shot][n_width]);
        }
    }
    cout << answer << "\n" << flush;
    return 0;
}

