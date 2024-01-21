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
    int N,M;
    cin >> N >> M;
    vector<int> A(N,0);
    vector<int> B(N+10,0);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    unordered_map<int,int> mymap;
    for(int j=0;j<N;j=j+1){
        B[j+1]=(B[j]+A[j])%M;
    }
    // for(auto& b:B){
    //     debug("%lld ",b);
    // }
    // debug("\n");
    for(int j=0;j<=N;j=j+1){
        mymap[B[j]]=mymap[B[j]]+1;
    }
    ll ans = 0;
    for(auto& m:mymap){
        // debug("余り%d -> %d\n",m.first,m.second);
        ll cnt=m.second;
        ans=ans+((cnt-1)*cnt)/2;
    }
    // debug("\n");
    cout << ans << "\n" << flush;
    // for(auto &e:mymap){
    //     debug("余り %d -> %d 個\n",e.first,e.second);
    // }
    return 0;
}
