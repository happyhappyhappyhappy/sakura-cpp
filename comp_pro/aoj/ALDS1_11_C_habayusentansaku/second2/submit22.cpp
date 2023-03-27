#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/t_debug.h"
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
const ll yamaMAX_LL = 1LL << 58;

// 大域変数

Graph G;
vector<int> dist;
int N;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void GShow(int N){
    for(int j=0;j<N;j=j+1){
        for(int k=0;k<N;k=k+1){
            if(G[j][k]==yamaMAX_INT){
                debug("  *");
            }
            else{
                debug(" %d",G[j][k]);
            }
        }
        debug("\n");
    }
    debug("\n");
}

int main(void){
    initial();
    cin >> N;
    G.assign(N,vector<int>(N,yamaMAX_INT));
    dist.assign(N,yamaMAX_INT);
    for(int j=0;j<N;j=j+1){
        int u;
        cin >> u;
        u = u-1;
        int linec;
        cin >> linec;
        for(int k=0;k<linec;k=k+1){
            int v;
            cin >> v;
            v = v - 1;
            G[u][v] = 1;
        }
    }
    GShow(N);
    return 0;
}
