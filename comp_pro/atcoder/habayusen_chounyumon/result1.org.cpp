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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showG(vector<vector<int>> &G,int N){
    for(int j=0;j<N;j=j+1){
        debug1(" %d :",j);
        for(int k=0;k<(int)G[j].size();k=k+1){
            debug1(" %d",G[j][k]);
        }
        debug1("\n");
    }
}


int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int j=0;j<M;j++){
        int first,second;
        cin >> first >> second;
        G[first].push_back(second);
        G[second].push_back(second);
    }
    showG(G,N);
    // 幅優先に使う変数群
    vector<int> dist(N,-1);
    queue<int> que;
    // 初期化 0に今いる
    dist[0] = 0;
    que.push(0);
    while(que.empty() == false){
        int v = que.front(); // 先頭を取り出し
        que.pop(); // 先頭を削除
        debug(v);
        for(int nextv: G[v]){ // TODO: forをいつもやるように入れる。nextv=G[v][j]で
            if(dist[nextv]!=-1){ // 発見済み→次へ行く
                debug1("nextv %d は 発見済み 深さ %d\n",nextv,dist[nextv]);
                continue;
            }
            dist[nextv]=dist[v]+1;
            debug(v,nextv,dist[nextv]);
            que.push(nextv);
        }
    }
    for(int v=0;v<N;v=v+1){
        cout << v << " : " << dist[v] << "\n" << flush;
    }
    return 0;
}

