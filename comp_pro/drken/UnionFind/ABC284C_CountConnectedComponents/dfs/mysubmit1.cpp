#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
// #include"/wrk/sakura-cpp/lib/dump.hpp"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
Graph G;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfs(Graph &G,int pos,vector<bool> &seen){
    seen[pos]=true;
    debug("%dに来ました\n",pos);
    for(auto &v:G[pos]){
        if(seen[v]==true){
            debug("%d はすでに確認済みです。飛ばします\n",v);
            continue;
        }
        debug("%d をさらに深く探索へ行きます\n",v);
        dfs(G,v,seen);
    }
    return;
}

int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    Graph G(N);
    for(int j=0;j<M;j=j+1){
        int u,v;
        cin >> u >> v;
        u = u-1;
        v = v-1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> seen(N,false);
    int result = 0;
    for(int j=0;j<N;j=j+1){
        if(seen[j]==true){
            debug("%dはdfs使う前からチェック済みです。飛ばします。\n",j);
            continue;
        }
        result = result+1;
        dfs(G,j,seen);
    }
    cout << result << "\n" << flush;
    return 0;
}
