#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
// 2021/12/24 コイン問題dpの単純なアプローチで解いた物

// 大域変数
double dp[5][9];
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    for(int ii=0;ii < 5;++ii){
        for(int j=0;j < 9 ; ++j){
            dp[ii][j]=0.0;
        }
    }
    dp[0][0]=1.0;
}

int main(void){
    initial();
    for(int ii = 0;ii < 4;ii++){
        for(int j=0;j < 9;j++){
            // if(dp[ii][j] > 0.0){
            dp[ii+1][j+1] = dp[ii+1][j+1]+dp[ii][j]/2.0;
            dp[ii+1][j+2] = dp[ii+1][j+2]+dp[ii][j]/2.0;
            // }
        }
    }
    double answer = 0.0;
    for(int ii=6;ii<=8;ii++){
        answer = answer + dp[4][ii];
    }
    cout << answer << "\n" << flush;
    for(int ii=0;ii < 5;ii++){
        for(int j=0; j < 9;j++){
            cout << dp[ii][j] << " ";
        }
        cout << "\n" << flush;
    }
    return 0;
}
