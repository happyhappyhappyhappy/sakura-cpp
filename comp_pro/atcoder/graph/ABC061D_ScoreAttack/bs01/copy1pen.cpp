#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/lib/dump.hpp"
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
const ll INF=1LL<<50;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    const int NMAX=1000;
    const int MMAX=2000;
    vector<int> a(MMAX,0);
    vector<int> b(MMAX,0);
    vector<ll> c(MMAX,0);
    for(int j=0;j<M;j=j+1){
        cin >> a[j] >> b[j] >> c[j];
        c[j]=0-c[j];
    }
    vector<ll> dist(NMAX,INF);
    dist[0]=0;

    return 0;
}
