#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

int main(void){
    initial();
    int N;// 投げる回数
    int P;// この点以上になる確率
    cin >> N >> P;
    // N = 4;
    // P = 6;
    double DP[N+1][P+1];
    // DP初期化
    for(int j=0;j<=N;j++){
        for(int k=0;k<=P;k++){
            DP[j][k]=0.0;
        }
    }
    DP[0][0]=1.0;
    for(int j=0;j<4;j++){
        for(int k=0;k<7;k++){
            // どこに足すのかが重大
            DP[j+1][min(k+1,P)]=DP[j+1][min(k+1,P)]+DP[j][k]/2.0;
            DP[j+1][min(k+2,P)]=DP[j+1][min(k+2,P)]+DP[j][k]/2.0;
        }
    }
    cout << DP[N][P] << "\n" << flush;
    for(int j=0;j<=N;j++){
        for(int k=0;k<=P;k++){
            cout << DP[j][k] << "" ;
        }
        cout << "\n" << flush;
    }
    return 0;
}
