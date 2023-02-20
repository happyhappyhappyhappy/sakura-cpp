#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/touristdebug.h"
#else
#define debug1(...) 42
#define debug2(...) 42
#define debug(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
int M,N;
int maxtile=0;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void GShow(int M,int N,vector<vector<int>> &G){
    debug1("INSERT\n");
    for(int j=0;j<N;j=j+1){
        for(int k=0;k<M;k=k+1){
            debug1(" %d",G[j][k]);
        }
        debug1("\n");
    }
}

void dfs(vector<vector<int>> G,int j,int k,int deepth){
    // TODO: HERE
}

int main(void){
    initial();
    cin >> M;
    cin >> N;
    vector<vector<int>> G(N+2,vector<int>(M+2,2));
    for(int j=0;j<N;j=j+1){
        for(int k=0;k<M;k=k+1){
            cin >> G[j+1][k+1];
        }
    }
    GShow((int) G[0].size(),(int) G.size(),G);
    int result;
    for(int j=0;j<(int)G.size();j=j+1){
        for(int k=0;k<(int)G[0].size();k=k+1){
            if(G[j][k]==1){
                dfs(G,j,k,0);
            }
        }
    }
    return 0;
}

