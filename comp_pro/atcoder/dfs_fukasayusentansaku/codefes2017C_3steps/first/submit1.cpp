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

// 大域変数
int N=0;
int M=0;
// グラフ表現
vector<vector<int>> G; // ここでは敢えて個数と初期値は入れない
// 二部グラフ用色分け配列
vector<int> dist;// 同様
// 二部グラフ判定
bool isbg=true;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showG(void){
    for(int j=0;j<(int)G.size();j=j+1){
        debug("頂点 %3d から\n\t",j);
        for(int k=0;k<(int)G[j].size();k=k+1){
            debug(" %2d",G[j][k]);
        }
        debug("\n");
    }
}

void dfs(int e,int color){
    dist[e]=color;
    for(int j=0;j<(int)G[e].size();j=j+1){
        int next = G[e][j];
        if(dist[next]==-1){
            debug("まだ今の%2dから未探索な頂点%2dにアクセスする\n",e,next);
            int nextcolor = 1-color;
            debug("色は%2dとする\n",nextcolor);
            dfs(next,nextcolor);
        }
        else{
            if(dist[next]==1-color){
                debug("頂点 %2dについて、色が前のと同じなので前から来たのだろう。スキップ\n",next);
                continue;
            }
            else{
                debug("頂点 %2dについて、以前行ったはずなのだが頂点の色が想定していない。従って二部グラフでは無い\n",next);
                isbg=false;
            }
        }
    }
}
int main(void){
    initial();
    cin >> N >> M;
    G.assign(N,vector<int>());
    dist.assign(N,-1);
    for(int j=0;j<M;j=j+1){
        int u=0;
        int v=0;
        cin >> u >> v;
        u = u - 1;
        v = v - 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    showG();
    dfs(0,0);
    ll answer=0;
    if(isbg){
        int B=0; // color 0
        int W=0; // color 1
        for(int j=0;j<N;j=j+1){
            if(dist[j]==0){
                B=B+1;
            }
            else{
                W=W+1;
            }
        }
        answer = (ll)B*(ll)W-(ll)M;
    }
    else{
        answer = ((ll)N*(ll)(N-1))/2-(ll)M;
    }
    cout << answer << "\n" << flush;
    return 0;
}
