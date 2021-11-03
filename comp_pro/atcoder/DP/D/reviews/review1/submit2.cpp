#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<endl
template<class XXX> inline bool changeMax(XXX& x,XXX y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

// 与える型DPを適用している→失敗。漸化式に違和感。
ll N,W;
ll weight[101010],value[110];
ll DP[110][101010];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(auto x=0;x < 110; x++){
        for(auto y=0;y < 101010;y++)
        {
            DP[x][y]=0;
        }
    }
}

int main(void){
    initial();
    cin >> N >> W;
    for(auto x=0;x < N;x++){
        cin >> weight[x] >> value[x];
    }
    for(auto j=0;j<N;j++){
        for(auto k=0;k<=W;k++){
            // まだ詰められる場合
            if(k+weight[j]<=W){
                changeMax(DP[j+1][k],DP[j][k+weight[j]]+value[j]);
            }
            // 詰められない＋様子見がベストの場合
            changeMax(DP[j+1][k],DP[j][k]);
        }
    }
    for(auto j=0;j<=W;j++){
        for(auto k=0;k<N;k++){
            cout << DP[k][j] << " ";
        }
        cout << "\n";
    }
    cout << DP[N][W] << "\n";
    return 0;
}