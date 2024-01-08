#include<bits/stdc++.h>
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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N,S,T;
    ll W;
    cin >> N >> W;
    // 下は200000で固定 人数では無い
    vector<ll> P(N+1,0); // いもす法データ収集
    vector<ll> Ac(N+2,0); // 累積和
    for(int j=0;j<N;j=j+1){
        ll p;
        cin >> S >> T >> p;
        P[S]=p;// 開始
        P[T]=p*(-1) ;// リセット
    }
    for(int j=0;j<N;j=j+1){
        Ac[j+1]=Ac[j]+P[j];
    }
    for(auto& e:Ac){
        debug("%lld ",e);
    }
    debug("\n");
    return 0;
}
