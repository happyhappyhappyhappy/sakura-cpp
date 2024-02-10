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
using ll=long long int;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
ll mypow(ll p,ll n){
    ll x = 1;
    while(0<n){
        if((n&1)==1){
            x = x * p;
        }
        n = n >> 1;
        p = p * p;
    }
    return x;
}
vector<ll> makeList(int cnt){
    vector<ll> res;
    res.push_back(-1);
    for(int j=0;j<cnt;j=j+1){
        res.push_back(mypow(j+1,j+1));
    }
    return res;
}
int main(void){
    initial();
    ll q;
    cin >> q;
    vector<ll> apowas=makeList(15);
    // for(auto& e:apowas){
    //     cout << e << endl;
    // }
    return 0;
}
