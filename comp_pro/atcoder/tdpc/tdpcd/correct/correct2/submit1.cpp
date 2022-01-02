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
    ll N,D;
    cin >> N >> D; // N => サイコロを振る回数,D => 振った結果この倍数か
    int pf[3]={0,0,0};
    int div[3] = {2,3,5};
    for(int j=0;j<3;j=j+1){
        while(D % div[j] == 0){
            pf[j]=pf[j]+1;
            D = D / div[j];
        }
    }
    if( D != 1 ){
        cout << 0.0 << "\n" << fflush;
    }
    double dp[N+1][pf[0]+1][pf[1]+1][pf[2]+1]=1.0;
    const int di[6]={0,1,0,2,0,1}; // サイコロに対する2の倍数
    const int dj[6]=[0,0,1,0,0,1]; // サイコロに対する3の倍数
    const int dk[6]={0,0,0,0,1,0}; // サイコロに対する5の倍数
    for(int n=0;n<N;n++){
        for(int i=0;i<=pf[0];i=i+1){
            for(int j=0;j<=pf[1];j=j+1){
                for(int k=0;k<=pf[2];k=k+1){
                    for(int d=0;d<6;d=d+1){
                        int ni=min(pf[0],i+di[d]);
                        int nj=min(pf[1],j+dj[d]);
                        int nk=min(pf[2],k+dk[d]);
                        // 自分式にやり直した⇒正解したので一旦保留
                        // https://ben2suzuka.hatenablog.com/entry/8
                        // dp[n+1][ni][nj][nk]=
                    }
                }
            }
        }
    }
    return 0;
}
