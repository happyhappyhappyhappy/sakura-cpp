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

bool isbi = true; // 2部グラフかどうかの判定

void showG(void){
    for(int j=0;j<(int)G.size();j=j+1){
        debug("%dから\n\t",j);
        for(int k=0;k<(int)G[j].size();k=k+1){
            debug("%3d,",G[j][k]);
        }
        debug("\n");
    }
}

void dfs(int v,int d){
    dir[v]=d;
    for(int j=0;j<(int)G[v].size();j=j+1){
        int check=G[v][j];
        if(dir[check]==-1){
            debug("まだ未探索の %2d の位置に %2d を入れていきます\n",check,1-d);
            dfs(check,1-d);
        }
        else{
            if(dir[check]==1-d){
                debug("dir[%d]=%dの為飛ばします\n",check,1-d);
                continue;
            }
            else{
                debug("dir[%d]!=%dの無い為二部グラフと分かりました\n",check,1-d);
                isbi=false; // 二部グラフでは無い
            }
        }
    }
}

int main(void){
    initial();
    cin >> N >> M;
    dir.assign(N,-1);
    G.assign(N,vector<int>());
    for(int j=0;j<M;j=j+1){
    //        debug("辺 %2d\n",j);
        int u=0;
        int v=0;
        cin >> u >> v;
    //    debug("得られた値 %2d <-> %2d\n",u,v);
        u = u-1;
        v = v-1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    showG();
    dfs(0,0);
    int result;
    if(isbi){
        debug("Gは二部グラフになります\n");
        int B=0;
        int W=0;
        for(int j=0;j<N;j=j+1){
            if(dir[j]==0){
                W=W+1;
            }
            else{
                B=B+1;
            }
            debug("黒 : %2d 個,白 : %2d 個\n",B,W);
            result = W*B-M;
        }
    }
    else{
        debug("Gは一筆書きができるオイラーグラフです\n");
        result = (N*(N-1))/2-M;
    }
    cout << result << "\n" << flush;
    return 0;
}
