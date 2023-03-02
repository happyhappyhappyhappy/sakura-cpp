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

void showG(vector<vector<int>> G){
    int P=(int)G.size();
    for(int j=0;j<P;j=j+1){
        debug(G[j]);
    }
}

int main(void){
    initial();
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int j=0;j<N;j++){
        int tmp,point;
        cin >> tmp >> point;
        for(int k=0;k<point;k=k+1){
            int nextpos;
            cin >> nextpos;
            nextpos=nextpos-1; // 0-indexに修正
            G[j].push_back(nextpos);
            // 逆は無い G[nextpos].push_back(j);
        }
    }
    showG(G);
    vector<int> dist(N,-1);
    queue<int> que;
    // 初期化
    dist[0]=0;
    que.push(0);
    while(que.empty()==false){
        int pos=que.front();
        for(int j=0;j<(int)G[pos].size();j=j+1){
            int nextpos=G[pos][j];
            if(dist[nextpos]!=-1){ // もうすでに計算済み
                continue;
            }
            else{
                que.push(nextpos);
                dist[nextpos]=dist[pos]+1;
            }
        }
        que.pop();
    }
    for(int j=0;j<N;j=j+1){
        cout << j+1 << " " << dist[j] << "\n" << flush;
    }
    return 0;
}

