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
using Edge=pair<int,ll>;
using P2P=pair<int,int>; // 根から根情報 TO,FROM
using Graph=vector<vector<Edge>>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

Graph G;
vector<int> c_code;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfs(int to,int from,int color){
    c_code[to]=color;
    for(int j=0;j<(int)G[to].size();j=j+1){
        Edge nextpos = G[to][j];
        int nextpos_to=nextpos.first;
        ll nextpos_dir=nextpos.second;
        if(nextpos_to == from){
            continue;
        }
        else{
            if(nextpos_dir & 1){
                dfs(nextpos_to,to,1-c_code[to]);
            }
            else{
                dfs(nextpos_to,to,c_code[to]);
            }
        }
    }

}

void solver(void){
    dfs(0,-1,1);
}

int main(void){
    initial();
    int N; cin >> N;
    G.assign(N,vector<Edge>());
    c_code.assign(N,0);
    for(int j=0;j<N-1;j++){
        int u,v;
        cin >> u >> v;
        ll w;
        cin >> w;
        u=u-1;
        v=v-1;
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    solver();
    for(int j=0;j<N;j=j+1){
        cout << c_code[j] << " ";
    }
    cout << "\n" << flush;
    return 0;
}
