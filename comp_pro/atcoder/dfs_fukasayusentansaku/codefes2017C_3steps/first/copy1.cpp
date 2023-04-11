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

int N,M;
vector<vector<int>> G;
vector<int> dir;

bool isbi = true;

void showG(void){
    for(int j=0;j<(int)G.size();j=j+1){
        debug("%dから\n\t",j);
        for(int k=0;k<(int)G[j].size();k=k+1){
            debug("%3d,",G[j][k]);
        }
        debug("\n");
    }
}

int main(void){
    initial();
    cin >> N >> M;
    // debug("%3d %3d\n",N,M);
    dir.assign(N,-1);
    G.assign(N,vector<int>());
    for(int j=0;j<M;j=j+1){
        debug("辺 %2d\n",j);
        int u=0;
        int v=0;
        cin >> u >> v;
        debug("得られた値 %2d <-> %2d\n",u,v);
        u = u-1;
        v = v-1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // showG();
    return 0;
}
