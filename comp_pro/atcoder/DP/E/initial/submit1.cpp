#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
template<class XXX> inline bool chmin(XXX& a,XXX b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}


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
    int N;
    ll W;
    cin >> N >> W;
    for(int j=0;j<N;j++){
        cin >> weight[j] >> value[j];
    }
    for(int item=0;item<=N;item++){
        for(int sum_value=0;sum_value < MAX_V;sum_value++ ){
            if(sum_value-value[item] >= 0){
                // sum_value >= value[item] なら選べる(下限)
                chmin(DP[item+1][sum_value],DP[item][sum_value-value[item]]+weight[item]);
            }
            // ここでは選ばない場合
            chmin(DP[item+1][sum_value],DP[item][sum_value]);
        }        
    }
    ll checkervalue=MAX_V-1;
    while(checkervalue--){
        if(DP[N][checkervalue]<=W){
            break;
        }
    }
    cout << checkervalue << "\n" << flush;
    
    return 0;
    }

