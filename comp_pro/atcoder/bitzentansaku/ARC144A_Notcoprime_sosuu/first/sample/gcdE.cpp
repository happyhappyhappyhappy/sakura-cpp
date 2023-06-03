#include<bits/stdc++.h>
// 拡張ユークリッド互除法も含めたもの。
// 逆元の余りを求めるロジックのため互いに素以外はあまり使わない
//2023-06-03 19:24:24
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
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll gcd(ll x,ll y){
    if(y == 0){
        debug("y = 0 のため x = %3lld を返します\n",x);
        return x;
    }
    else{
        ll z = x % y;
        debug("y は 0ではないので x を %3lld , y を %3lld にして再帰します\n",y,z);
        return gcd(y,z);
    }
}
ll gcdExt(ll a,ll b,ll &x,ll &y){
    debug("a = %3lld ,b = %3lld , x = %3lld , y = %3lld で入りました",
    a,b,x,y);
    if(b == 0){
        debug("b = %3lld の為, a = %3lld をGCDとして送ります\n",b,a);
        x = 1;
        y = 0;
        debug("また、ここで x = %3lld , y = %3lld と設定しました\n",x,y);
        return a;
    }
    ll c = a % b;
    debug("a = %3lld ,b = %3lld , x = %3lld , y = %3lld として再帰します\n",
    b,c,y,x);
    ll d = gcdExt(b,c,y,x);
    y = y - (a/b)*x;
    debug("x = %3lld, y = %3lld になりました\n",x,y);
    return d;
}

int main(void){
    initial();
    ll M=0;
    ll N=0;
    cin >> M >> N;
    ll res=gcd(M,N);
    cout << "従来のユークリッドのみ -> " << res << "\n" << flush;
    ll x=-1;
    ll y=-1;
    res = gcdExt(M,N,x,y);
    cout << "拡張ユークリッド -> " << res << "\n" << flush;
    cout <<  "逆元手がかり ->  " << x << " or " << (x+N) << "\n" << flush;
    return 0;
}
