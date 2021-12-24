#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
// 2021/12/24 コイン問題dpの単純なアプローチで解いた物

// 大域変数
const int repel = 4;
const int summax = 8;
double dp[repel+1][summax+1];
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    for(int ii=0;ii <= repel;++ii){
        for(int j=0;j<=summax ; ++j){
            dp[ii][j]=0.0;
        }
    }
    dp[0][0]=1.0;
}

int main(void){
    initial();
    // 動的計画法の処理 
    return 0;
}
