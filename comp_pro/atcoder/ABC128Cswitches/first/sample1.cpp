#include<bits/stdc++.h>
using namespace std;
// using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
int main(void){

    int N,M; // スイッチの数,電球の数
    cin >> N >> M;
    vector<vector<int>> S(10,vector<int>(0)); // Sはint型のvectorになっている
    vector<int> P(10); // 2で割った値がこの値になっていれば光る
    for(int j=0;j<M;j=j+1) // 電球jはスイッチがONになっていれば光る前提か
    {
        int pat ;
        cin >> pat;
        for(int k=0;k<pat;k=k+1){
            int s;
            cin >> s;
            s=s-1; // 0-indexにする
            S[j].push_back(s);
        }
//        debug("%d の要素の数は %ld です\n",j,S[j].size());
    }
    for(int j = 0;j<M;j=j+1){
        cin >> P[j];
    }
    debug("入力した情報を出力します\n");
    for(int j=0;j<M;j=j+1){
        debug("電球 %d\n",j);
        debug("利用するスイッチ\n");
        for(int k=0;k<S[j].size();k=k+1){
            debug("%d ",S[j].at(k));
        }
        debug("\n");
        debug("上記のスイッチの内");
        if(P[j] == 1){
            debug("奇数個");
        }
        else{
            debug("偶数個");
        }
        debug("ONになっていれば付きます\n");
    }
    int ans = 0;
    for(int bit=0;bit < (1<<N);bit=bit+1){
        int ok=0;
        #define fore(i,a) for(auto &i:a)
        for(int jm=0;jm<M;jm=jm+1){;
            int cnt=0;
            for(auto s:S[jm]){
                if((bit & (1<<s))!=0){
                    cnt = cnt+1; // 付いた
                }
            }
        }
        if(ok == M){
            ans = ans+1;
        }
    }
    cout << ans << "\n" << flush;
    return 0;
}
