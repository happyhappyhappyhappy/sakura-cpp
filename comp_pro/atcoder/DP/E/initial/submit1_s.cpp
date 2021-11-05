#include<iostream>
using namespace std;
template<class T> inline bool chmax(T& a,T b)
    {
        if( a < b )
            {
                a = b;
                return true;
            }
        return false;
    }
template<class T> inline bool chmin(T& a,T b)
    {
        if( a > b)
            {
                a=b;
                return true;
            }
        return false;
    }
const long long INF=1LL << 60;// INFは固定値long long型

const int MAX_N=110; // N の最大値は110 MAX_N は int型
const int MAX_V=100100; // VALUEの最大値 int型 

// 入力データ
int N; // Nはint型
// 入力された重さはlong long型。また重さと価値もlong long型
long long W,weight[MAX_N],value[MAX_N];
// DPテーブル 1項目目は荷物のデータ 2項目目は価値のデータ long long型
long long dp[MAX_N][MAX_V];

int main(void){
    cin >> N >> W;
    for(int i=0;i<N;++i){
        cin >> weight[i] >> value[i];
    }
    // 初期化
    for(int i=0;i<MAX_N;++i){
        for(int j=0;j<MAX_V;++j){
            dp[i][j] = INF;
        }
    }
    // 初期条件
    dp[0][0] = 0;
    // DPループ
    for(int i=0;i<N;++i){
        for(int sum_v=0;sum_v<MAX_V;++sum_v){
            // i番目の荷物を選ぶ場合
            if(sum_v-value[i]>=0){
                chmin(dp[i+1][sum_v],dp[i][sum_v-value[i]]+weight[i]);
            }
            // i番目の荷物を選ばない場合、もしくは得られない場合
            chmin(dp[i+1][sum_v],dp[i][sum_v]);
        }
    }
    // 最適値の出力
    long long res=0; // 解答はlong long 型
    for(int sum_v=0;sum_v<MAX_V;++sum_v){
        if(dp[N][sum_v]<=W){
            res = sum_v;
        }
    }
    cout << "DrKen型:" << res << "\n";
    long long res2=MAX_V-1;
    while(dp[N][res2]>W){
        res2 = res2 - 1;
    }
    cout << "Friend型:" << res2 << "\n";
}
