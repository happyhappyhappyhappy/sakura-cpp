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
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
bool makePrimes(int T,vector<ll> &X){
    vector<bool> isPrime(T+1,true);
    isPrime[0]=false;
    isPrime[1]=false;
    isPrime[2]=true;
    for(int j=2;j<=T;j=j+1){
        if(isPrime[j]==false){
            debug("%3d は素数ではありませんでしたskip\n",j);
            continue;
        }
        for(int k=j*j;k<=T;k=k+j){
            debug("%3d を素数権利から剥奪します\n",k);
            isPrime[k]=false;
        }
    }
    for(int j=0;j<=T;j=j+1){
        if(isPrime[j]){
            X.push_back((ll)j);
        }
    }
    return true;
}
int main(void){
    initial();
    int N=0;
    cin >> N;
    vector<ll> primes={};
    if(makePrimes(N,primes)){
        cout << N << " までの素数 → ";
        for(int j=0;j<(int)primes.size();j=j+1){
        cout << primes[j] << " ";
        }
    cout << "\n" << flush;
    }
    return 0;
}
