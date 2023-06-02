#include<bits/stdc++.h>
// エラトスエヌスの篩い実験 2023-06-02 17:34:26
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

int main(void){
    initial();
    int N=0;
    cin >> N;
    vector<bool> isPrime(N+1,true);
    isPrime[0]=false;
    isPrime[1]=false;
    isPrime[2]=true;
    for(int j=2;j<=N;j=j+1){
        if(isPrime[j]==false){
            debug("%3d は素数ではありません-> Skip\n",j);
            continue;// もうすでに判明している→次へ
        }
        for(int k=j*j;k<=N;k=k+j){// k は jの倍数→素数権利剥奪
            debug("%3d を素数権利から剥奪します\n",k);
            isPrime[k]=false;
        }
    }
    vector<ll> primeNum={};
    debug("素数の一覧 ");
    for(int j=0;j<=N;j=j+1){
        if(isPrime[j]){
            debug(" %3d",j);
            primeNum.push_back(ll(j));
        }
    }
    debug("\n");
    cout << "素数一覧";
    for(int j=0;j<(int)primeNum.size();j=j+1){
        cout << " " << primeNum[j];
    }
    cout << "\n" << flush;
    return 0;
}
