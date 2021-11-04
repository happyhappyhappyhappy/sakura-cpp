#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<endl

template<class XXX> bool maxChange(XXX& x,XXX y){
    if(x<y){
        x = y;
        return true;
    }
    return false;
}
template<class XXX> bool minChange(XXX& x,XXX y){
    if(x>y){
        x=y;
        return true;
    }
    return false;
}
// 大域変数
// 配列絡みはconst定義も加えないとダメ

const int MAX_N=110;
const int MAX_VALUE=110*1000;

// 配列無関係の大域変数
ll INF=1LL<<61; // 無限の値→重さの最大値として利用
int N; // 荷物の数
ll W; // 利用できる重さの最大
// 何個目の荷物か？現在の価値はいくらか？で重さが出てくるDP
ll DP[MAX_N][MAX_VALUE];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int j=0;j<MAX_N;j=j++){
        for(int k=0;k<MAX_VALUE;k++){
            DP[j][k] = INF;
        }
    }
    // これだけ初期値。何も入れていなければ重さは無い
    DP[0][0]=0;
}

int main(void){
    initial();
    cin >> N >> W;
    // 面倒なのでここで物と重さの配列を作って入れてしまえ
    int value[N];
    int weight[N];
    for(int j=0;j<N;j++){
        cin >> value[j] >> weight[j];
    }
    for(int j=0;j<=N;j++){
        for(int k=0;k<MAX_VALUE;k++){
            if(k-value[j]>=0){ // 2つめの要素「価格」が0にならなければこの比較を行う
                minChange(DP[j+1][k],DP[j][k-value[j]]+weight[j]);
            }
            // 価格が0以下になってしまう。もしくは意図的にそのままにする
            minChange(DP[j+1][k],DP[j][k]);
        }
    }
    // 全部埋め尽くしたときDPにあるデータを見てW以下を満たす＋2つめの要素が最大になるデータを求める
    // drken型チェック
    ll answerA=0;
    for(int j=0;j<MAX_VALUE;j++){
        if(DP[N][j]<=W){
            maxChange(answerA,DP[N][j]);
        }
    }
    // friend型チェック
    int answerB=MAX_VALUE-1;
    while(DP[N][answerB]>W){
        answerB=answerB-1;
    }
    cout << "drken :" << answerA << "\n";
    cout << "friend:" << answerB << "\n";

    return 0;
}