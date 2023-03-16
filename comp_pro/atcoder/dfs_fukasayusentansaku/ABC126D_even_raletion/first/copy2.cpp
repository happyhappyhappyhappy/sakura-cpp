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

int main(void){
    initial();
    cin >> N;
    G.assign(N,vector<Edge>());
    for(int j=0;j<N-1;j=j+1){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        u = u -1;
        v = v -1;
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    return 0;
}

