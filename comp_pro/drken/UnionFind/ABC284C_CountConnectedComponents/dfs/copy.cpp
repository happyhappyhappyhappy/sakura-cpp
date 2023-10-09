#include<bits/stdc++.h>
using namespace std;

using Graph=vector<vector<int>>;

void dfs(const Graph &G,int v,vector<bool> &seen){
    seen[v]=true;
    for(auto v2:G[v]){
        if(seen[v2]) continue;
        dfs(G,v2,seen);
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    Graph G(N);
    for(int j=0;j<M;++j){
        int u,v;
        cin >> u >> v;
        u = u-1;
        v = v-1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int res=0;
    vector<bool> seen(N,false);
    for(int v=0;v<N;v=v+1){
        if(seen[v])continue;
        res=res+1;
        dfs(G,v,seen);
    }
    cout << res << endl;
}
