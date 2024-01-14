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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    vector<int> P(M);
    vector<int> Y(M);
    for(int j=0;j<M;j=j+1){
        cin >> P[j] >> Y[j];
        P[j]=P[j]-1;
    }
    vector<vector<int>> V(N); // 県毎にまとめる二次ベクトル
    for(int j=0;j<M;j=j+1){
        V[P[j]].push_back(Y[j]);
    }
    // for(int j=0;j<N;j=j+1){
    //     for(auto& x:V[j]){
    //         debug("%d ",x);
    //     }
    //     debug("\n");
    // }
    // debug("-----\n");
    for(int v=0;v<N;v=v+1){
        sort(V[v].begin(),V[v].end());
        V[v].erase(unique(V[v].begin(),V[v].end()),V[v].end());
    }
    // for(int j=0;j<N;j=j+1){
    //     for(auto& x:V[j]){
    //         debug("%d ",x);
    //     }
    //     debug("\n");
    // }
    // debug("-----\n");
    for(int j=0;j<M;j=j+1){
        int v=P[j];
        int id=lower_bound(V[v].begin(),V[v].end(),Y[j])-V[v].begin();
        // debug("%d-%d\n",v+1,id+1);
        printf("%06d%06d\n",v+1,id+1);
    }
    return 0;
}
