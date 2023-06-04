#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
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
ll extGCD(ll M,ll N,ll &x,ll &y){
    ll res=0;
    if(N == 0){
        res=M;
        x = 1;
        y = 0;
        return res;
    }
    res = extGCD(N,M%N,y,x);
    y = y - (M/N)*x;
    return res;
}
int main(void){
    initial();
    ll M=0;
    ll N=0;
    cin >> M >> N;
    ll x=-1;
    ll y=-1;
    ll gcd=0;
    gcd = extGCD(M,N,x,y);
    if(x<0){
        x=x+N;
    }
    cout << gcd << "\n" << flush;
    debug("%3lld を分子にした分数の %3lld で割った余り %3lld\n",M,N,x);
    return 0;
}
