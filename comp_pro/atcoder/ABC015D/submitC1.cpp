#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<endl
using namespace std;
using ll=long long;

template<class XXX> inline bool changeMax(XXX& x,XXX y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
} 
// 大域変数DP 与えられた枚数→今貼っている枚数→今現在の幅の長さ を要素とし、価値がこの中に入る
const int maxPhoto=55;
const int maxusePhoto=55;
const int maxWidth=11000;
int DP[maxPhoto][maxusePhoto][maxWidth];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int x=0;x < maxPhoto;x=x+1){
        for(int y=0;y < maxusePhoto;y=y+1){
            for(int z=0;z < maxWidth;z=z+1){
                DP[maxPhoto][maxusePhoto][maxWidth]=-1;
            }
        }
    }
    DP[0][0][0]=0; // 何も貼っていなければ価値はどこにもない
}

int main(void){
    initial();
    int W;
    cin >> W;
    int N,K;
    cin >> N >> K;
    vector<int> HABA(N);
    vector<int> KATI(N);
    for(int j=0;j<N;j=j+1){
        cin >> HABA[j] >> HIROSA[j];
    }
    for(int j=0;j < N;j=j+1){
        for(int aviableK=0;aviableK<=K;aviableK=aviableK+1){
            for(int width=0;width<=W;width=width+1){
                if(width+HABA[j] <= W){
                    DP[j+1][aviableK+1][width+HABA[j]]=
                    max(DP[j][aviableK][width]+KATI[j],DP[j][aviableK][width+HABA[j]]);
                }
            }
        }
    }

    return 0;
}
