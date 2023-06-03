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
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void primeSet(vector<ll> &X,ll P){//


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
    return 0;
}
