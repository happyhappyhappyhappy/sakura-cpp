#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
// EDPC Eを意識してDP配列の宣言
// 配列要素の数
const int MAX_N=110;
const int MAX_VALUE=MAX_N*1000;
const ll INF=1LL<<61;
// 各DPの宣言

ll DP1[MAX_N][MAX_VALUE]; // j++ 当初に設定したインクリメント
ll DP2[MAX_N][MAX_VALUE]; // ++j 修正したインクリメント
ll DP3[MAX_N][MAX_VALUE]; // j=j+1 素直にやってみるインクリメント

int main(void){
    // 入出力初期化
    ios::sync_with_stdio(false);
    cin.tie(0);
    system_clock::time_point start[3],end[3];
    double elaspd[3];
    // パターン1 j++
    start[0]=system_clock::now();
    for(int j=0;j<MAX_N;j++){
        for(int k=0;k<MAX_VALUE;k++){
            DP1[j][k]=INF;
        }
    }
    DP1[0][0]=0;
    end[0]=system_clock::now();
    // パターン2 ++j
    start[1]=system_clock::now();
    for(int j=0;j<MAX_N;++j){
        for(int k=0;k<MAX_VALUE;++k){
            DP2[j][k]=INF;
        }
    }
    DP2[0][0]=0;
    end[1]=system_clock::now();
    // パターン3 j=j+1
    start[2]=system_clock::now();
    for(int j=0;j<MAX_N;j=j+1){
        for(int k=0;k<MAX_VALUE;k++){
            DP3[j][k]=INF;
        }
    }
    DP3[0][0]=0;
    end[3]=system_clock::now();
    elaspd[0]=chrono::duration_cast<chrono::microseconds>
    (end[0]-start[0]).count();
    





    return 0;
}