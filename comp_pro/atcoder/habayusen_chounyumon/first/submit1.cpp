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

int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    vector<vector<bool>> G(N,vector<bool>(N,false)); // グラフ
    for(int j=0;j<M;j=j+1){
        int frompos,topos;
        cin >> frompos >> topos;
        G[frompos][topos]=true;
        G[topos][frompos]=true;
    }
    // 位置情報
    vector<int> dist(N,-1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while // TODO: 「何の情報がどうなるまで永遠に実行する。それは何か？」
    return 0;
}
