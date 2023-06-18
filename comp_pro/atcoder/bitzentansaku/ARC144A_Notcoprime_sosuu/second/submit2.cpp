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
template<class XXX> bool chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}
vector<ll> P50;
ll P_MAX=50LL;

void primeSet(void){
    vector<bool> isPrime(P_MAX,true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(ll j=0;j<P_MAX;j=j+1){
        if(isPrime[j]==false){
            continue;
        }
        for(ll k=j*2;k<P_MAX;k=k+j){
            isPrime[k]=false;
        }
    }
    for(ll j=0;j<P_MAX;j=j+1){
        if(isPrime[j]==true){
            P50.push_back(j);
        }
    }
}
ll mygcd(ll M,ll N){
    if(N==0){
        return M;
    }
    ll d=0;
    ll P = M%N;
    d=mygcd(N,P);
    return d;
}

ll solver(const vector<ll> &Obj){
    ll ans = yamaMAX_LL;
    ll p50size=(ll)P50.size();
    vector<ll> timeObj;
    for(ll j=1;j<(1<<p50size);j=j+1){
        ll primeTime = 1;
        for(ll k=0;k<p50size;k=k+1){
            int x=(j>>k)&1;
            if(x==1){
                primeTime=primeTime*P50[k];
            }
        }
        ll Objsize=Obj.size();
        bool flag=true;
        for(ll k=0;k<Objsize;k=k+1)
            {
            if( mygcd(primeTime,Obj[k])==1)
                {
                    flag=false;
                }
            }
        if(flag==true)
        {
            chmin(ans,primeTime);
        }
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
    ll N;
    cin >> N;
    vector<ll> objectValue(N);
    for(int j=0;j<N;j=j+1){
        cin >> objectValue[j];
    }
    cout << solver(objectValue) << "\n" << flush;
    return 0;
}
