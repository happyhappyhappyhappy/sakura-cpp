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
const ll MAXP=50;

vector<ll> P50={};


ll myGCD(ll M,ll N){
    if(N==0){
        return M;
    }
    return myGDC(N,M%N);
}

void mkPrime(ll X){
    vector<bool> isPrime(X,true);
    isPrime[0]=false;
    isPrime[1]=false;
    isPrime[2]=true;
    for(ll j=2;j<=X;j=j+1){
        if(isPrime[j]==false){
            continue;
        }
        for(ll k=j*j;k<=X;k=k+j){
            isPrime[k]=false;
        }
    }
    for(ll j=0;j<=X;j=j+1){
        if(isPrime[j]){
            P50.push_back(j);
        }
    }
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // 固定値なので最初の内にセットしてしまう
    mkPrime(MAXP);
}
void showPrime(void){
    for(int j=0;j<(int)P50.size();j=j+1){
        debug(" %3lld",P50[j]);
    }
    debug("\n");
}
int main(void){
    initial();
    showPrime();
    int N=0;
    cin >> N;
    vector<ll> prob(N,1);
    for(int j=0;j<N;j=j+1){
        cin >> prob[j];
    }
    debug("互いに素以外としたいものは ->");
    for(int j=0;j<N;j=j+1){
        debug("%3lld ",prob[j]);
    }
    debug("\n");
    int allLen=(int)P50.size();
    for(ll j=(1<<allLen)-1;j > 0;j=j-1){
        vector<ll> primeChain={};
        for(int k=0;k<allLen;k=k+1){
            int flug=(j>>k) & 1;
            if(flug == 1){
                primeChain.push_back(P50[k]);
            }
        }
        ll ntimes=1LL;
        for(int k=0;k<(int)primeChain.size();k=k+1){
            ntimes=ntimes*primeChain[k];
        }
        // ntimesに求まった式が入った
        // debug2("%3lld で作る積は %3lldです",j,ntimes);
        // TODO: myGCDを使ってprob[]と互いに素で無いntimesを見つける
    }
    return 0;
}
