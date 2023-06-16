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

ll gcd2(ll M,ll N,ll &x,ll &y){
    if(N==0){
        x = 1;
        y = 0;
        return M;
    }
    ll d;
    d = gcd2(N,M%N,y,x);
    y = y - (M/N)*x;
    return d;
}

int main(void){
    initial();
    ll M,N;
    cin >> M >> N;
    ll x=-1;
    ll y=-1;
    ll d=0;
    d=gcd2(M,N,x,y);
    cout << "最大公約数 " << d << "\n" << flush;
    if(x<0){
        x = x+N;
    }
    cout << M << " の逆数を " << N << " で割ったときの余り " << x << "\n" << flush;
    return 0;
}
