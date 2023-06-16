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
void makePrimes(ll N,vector<ll> &X){
    vector<bool> p(N,true);
    p[0]=false;
    p[1]=false;
    p[2]=true;
    for(ll j=0;j<N;j=j+1){
        if(p[j]==false){
            debug("%lldは素数でないので検索終了します\n",j);
            continue;
        }
        for(ll k=j*j;k<N;k=k+j){
            p[k]=false;
            debug(" %lld は %lld の倍数のため素数ではありません\n",k,j);
        }
    }
    for(ll j=0;j<N;j=j+1){
        if(p[j]==true){
            X.push_back(j);
        }
    }
}
int main(void){
    initial();
    ll N;
    cin >> N;
    vector<ll> primes;
    makePrimes(N,primes);
    for(ll j=0;j<(ll)primes.size();j=j+1){
        cout << " " << primes[j] << " ";
    }
    cout << "\n" << flush;
    return 0;
}
