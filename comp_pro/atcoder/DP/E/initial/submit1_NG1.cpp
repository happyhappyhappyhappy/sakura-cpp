#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<endl
template<class XXX> inline bool changeMin(XXX& x,XXX y){
    if(x>y){
        x=y;
        return true;
    }
    return false;
}
template<class XXX> inline bool changeMax(XXX& x,XXX y){
    if(x<y){
        x = y;
        return true;
    }
    return false;
}
// 大域変数
// inf,max_n,max_v にconst を付ければエラー消える気がする
ll INF=1LL<<60;
int MAX_N=110;
int MAX_V=100100;
ll N,W;
ll weight[110],value[1100];
// 配列宣言する時に、単に変数を利用するのはまずい
ll DP[MAX_N][MAX_V];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(auto x=0;x<MAX_N;x++){
        for(auto y=0;y<MAX_V;y++){
            DP[x][y] = INF;
        }
    }
    DP[0][0]=0;
}
int main(void){
    initial();
    cin >> N >> W;
    for(ll x=0;x<N;x++){
        cin >> value[x] >> weight[x];
    }
    // まずDP処理を行う
    for(ll j=0;j<N;j++){
        for(ll k=0;k<MAX_V;k++){
            if( k - value[j] >= 0){
                changeMin(DP[j+1][k],DP[j][k-value[j]]+weight[j]);
            }
            changeMin(DP[j+1][k],DP[j][k]);
        }
    }
    ll answer=0;
    for(ll k=0;k<MAX_V;k++){
        if(DP[N][k]<=W){
            changeMax(answer,k);
        }
    }
    cout << answer << "\n";
    return 0;
}
