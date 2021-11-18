#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

// 固定値
const int MAX_N=110; // 最大アイテム数
const int MAX_V=1000*1.1*MAX_N; // 最大価値数
const ll INF=1LL<<61;
// DPテーブル
ll DP[MAX_N][MAX_V];
// その他大域にしたい変数
int value[MAX_N]; // 各アイテムの価値
ll weight[MAX_N]; // 各アイテムの重さ
ll max_weight; // 重さの限度

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int j=0;j<MAX_N;j++){
        for(int k=0;k<MAX_V;k++){
            DP[j][k]=INF;
        }
    }
    DP[0][0]=0;
}

int main(void){
    initial();
    for(int j=0;j<MAX_N;i++){

    }
    
    return 0;
    }

