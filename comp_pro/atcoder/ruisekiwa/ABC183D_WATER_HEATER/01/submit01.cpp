#include<bits/stdc++.h>
// WAと推定。累積和の0以上制限を消してみたとき
// 通りました。0以下にはならないということか。
// https://atcoder.jp/contests/abc183/submissions/49182119
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/lib/dump.hpp"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
const int R=200100;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int N,S,T;
    long long W;
    cin >> N >> W;
    // 下は200000で固定 人数では無い
    vector<long long> P(R+1,0); // いもす法データ収集
    vector<long long> Ac(R+2,0); // 累積和
    for(int j=0;j<N;j=j+1){
        ll p;
        cin >> S >> T >> p;
        P[S]=P[S]+p;// 開始
        P[T]=P[T]+p*(-1) ;// リセット
    }
    for(int j=0;j<R+10;j=j+1){
        Ac[j+1]=Ac[j]+P[j];
        // if(Ac[j+1]<0){// 0<=Ac[x]となるように調整するこれが勘所か?
        //     // debug("%d で0以下になったので修正\n",j+1);
        //     Ac[j+1]=0;
        // }
    }
    // for(int j=0;j<20;j=j+1){
    //     debug("%lld ",Ac[j]);
    // }
    // debug("\n");
    sort(Ac.begin(),Ac.end(),greater<long long>{});
    // debug("最大値 %lld\n",Ac[0]);
    // cout << "水の供給量 " << W << ",利用する水の量最大 " << Ac[0] << "\n" << flush;
    if(W < Ac[0]){
        cout << "No" << "\n" << flush;
    }else{
        cout << "Yes" << "\n" << flush;
    }
    return 0;
}
