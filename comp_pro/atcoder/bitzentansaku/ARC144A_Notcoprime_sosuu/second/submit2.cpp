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
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
vector<ll> P50;
ll P_MAX=50LL;

void primeSet(void){
    vector<bool> isPrime(P_MAX,true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(ll j=0;j<P_MAX;j=j+1){
        if(isPrime[j]==false){
            debug("%3lld は 素数ではないとわかるので外します\n",j);
            continue;
        }
        for(ll k=j*2;k<P_MAX;k=k+j){
            debug("%3lld は素数でないと分かりました。候補から外します\n",k);
            isPrime[k]=false;
        }
    }
    for(ll j=0;j<P_MAX;j=j+1){
        if(isPrime[j]==true){
            P50.push_back(j);
        }
    }

}
ll solver(void){
    ll ans = yamaMAX_LL;
    ll p50size=(ll)P50.size();
    debug("50までの素数の数は %lld です\n",p50size);
    for(ll j=0;j<(1<<p50size);j=j+1){

    }
    return ans;
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    primeSet();
}
int main(void){
    initial();
    for(ll j=0;j<(int)P50.size();j=j+1){
        debug("%3lld ",P50[j]);
    }
    debug("\n");
    cout << solver() << "\n" << flush;
    return 0;
}
