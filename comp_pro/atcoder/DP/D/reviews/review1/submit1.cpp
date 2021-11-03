#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<endl
template<class XXX> inline bool changeMax(XXX& x,XXX y){
    if(x<y){
        x = y;
        return true;
    }
    else{
        return false;
    }
}

// 大域変数
ll DP[110][100100];
ll N,W,weight[110],value[110];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(auto x=0;x<110;x=x+1){
        for(auto y=0;y<100100;y=y+1){
            DP[x][y] = 0;
        }
    }
}


int main(void){
    initial();
    cin >> N >> W;
    for(auto x=0;x<N;x=x+1){
        cin >> weight[x] >> value[x];
    }
    // 取り扱っている商品についてのfor文
    for(auto j=0;j<N;j=j+1){
        for(auto k=0;k <= W;k=k+1){
            // まず今のyの値で重さkで使えるものの場合。
            if(k-weight[j]>=0){
                changeMax(DP[j+1][k],DP[j][k-weight[j]]+value[j]);
            }
            // そのまま放置した場合の遷移
            changeMax(DP[j+1][k],DP[j][k]);
        }
    }
    cout << DP[N][W] << "\n";
    return 0;
}