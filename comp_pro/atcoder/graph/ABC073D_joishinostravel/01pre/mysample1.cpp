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
const long long INF=1LL << 60;


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N,M,R;
    cin >> N >> M >> R;
    vector<int> r;
    vector<vector<long long>> dist(N,vector<long long>(N,INF));
    for(int j=0;j<R;j=j+1){
        int r0;
        cin >> r0;
        r.push_back(r0-1);
    }
    for(int j=0;j<M;j=j+1){
        int a0,b0;
        long long c0;
        cin >> a0 >> b0 >> c0;
        dist[a0-1][b0-1]=c0;
    }
    debug("---経路---\n");
    for(int j=0;j<R;j=j+1){
        debug("%d ",r[j]);
    }
    debug("\n");
    debug("---今の設定距離---\n");
    for(int j=0;j<N;j=j+1){
        for(int k=0;k<N;k=k+1){
            long long x = dist[j][k];
            if(x == INF){
                debug("INF ");
            }else{
                debug("%3lld ",x);
            }
        }
        debug("\n");
    }
    debug("\n");
    return 0;
}
