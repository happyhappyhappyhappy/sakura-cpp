#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug1(...) 42
#define debug2(...) 42
#define debug(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
using Edge=pair<int,long long>;
using Graph=vector<vector<Edge>>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;
vector<vector<ll>> G;
vector<int> dir;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int N ;
    cin >> N ;
    dir.assign(N,0);
    G.assign(N);
    for(int j=0;j<N-1;j=j+1){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        u = u-1;
        v = v-1;
        G[u][v] = w;
        G[v][u] = w;
    }
    dfs(0,-1,0);
    return 0;
}

