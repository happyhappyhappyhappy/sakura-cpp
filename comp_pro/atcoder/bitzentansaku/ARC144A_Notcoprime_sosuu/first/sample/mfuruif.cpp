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
// NOW 2023-06-03 19:30:42
// 自分でテスト作成
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

void primeSet(vector<ll> &X,ll P){//
    vector<bool> isprime(P+1,true);
    isprime[0]=false;
    isprime[1]=false;
    isprime[2]=true;
    for(int j=2;j<=(int)P;j=j+1){
        if(isprime[j]==false){
            debug("%3d はすでに素数でないと判定されています->skip\n",j);
            continue;
        }
        for(int k=j*j;k<=P;k=k+j){
            isprime[k]=false;
            debug("%3d を素数で無いと決定しました\n",k);
        }
    }
    for(int j=0;j<=(int)P;j=j+1){
        if(isprime[j]){
            X.push_back((ll)j);
        }
    }

}

int main(void){
    initial();
    ll N;
    cin >> N;
    vector<ll> primes={};
    primeSet(primes,N);
    for(int j=0;j<(int)primes.size();j=j+1){
        cout << " " << primes[j];
    }
    cout << "\n" << flush;
    /** 補足50までの積はlonglongですべて求まるのか
    ->614889782588491410になります **/
    ll times=1;
    for(int j=0;j<(int)primes.size();j=j+1){
        times=times*primes[j];
    }
    ll timesll=yamaMAX_LL;
    debug("%3lld までの積は %3lldになります\n",N,times);
    debug(  "times -> %3lld ? %3lld <- maxLL \n",times,timesll);
    /**
     * times -> 614889782588491410 > 1152921504606846976 <- maxLL
     **/
    return 0;
}
