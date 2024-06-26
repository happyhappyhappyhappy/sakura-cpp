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
    int N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> s(N+1,0);
    for(int j=0;j<N;j=j+1){
        cin >> a[j];
    }
    for(int j=0;j<N;j=j+1){
        s[j+1]=s[j]+a[j];
    }
    // for(int j=0;j<N+1;j=j+1){
    //     debug("%lld ",s[j]);
    // }
    // debug("\n");
    map<ll,ll> nums;
    for(int j=0;j<N+1;j=j+1){
        ll val=s[j];
        nums[val]=nums[val]+1;
    }
    ll ans=0;
    for(auto &e:nums){
//        debug("%lld の個数 %lld\n",e.first,e.second);
        ll val = e.second;
        ans=ans+(val*(val-1))/2;
    }
    cout << ans << "\n" << flush;
//    map<ll,ll> nums;

    return 0;
}
