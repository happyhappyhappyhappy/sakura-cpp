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
using ll =long long;
using Edge = pair<int,long long>;
using Graph = vector<vector<Edge>>;

const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

int N;
Graph G;
vector<int> dir;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void dfs(int v,int p,int c){
    dir[v]=c;
    for(int j=0;j<(int)G[v].size();j=j+1){
        Edge e = G[v][j];
        debug(e.first,e.second);
        if(e.first == p){
            debug1("自分自身を見ているのでスキップ\n");
            continue;
        }
        if(e.second & 1){
            dfs(e.first,v,1-c);
        }
        else{
            dfs(e.first,v,c);
        }
    }
}

int main(void){
    initial();
    cin >> N;
    G.assign(N,vector<Edge>());
    for(int j=0;j<N-1;j=j+1){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        u=u-1;// 1-indexから0-index
        v=v-1;
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    dir.assign(N,0);
    dfs(0,-1,1);
    for(int j=0;j<N;j=j+1){
        cout << dir[j] << "\n" << flush;
    }
    return 0;
}

