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

static const int N = 100;
static const int INF = (1<<21);

int n,M[N][N];
int d[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    // 初期化
    for(int j=0;j<n;j++){
        d[j]=INF;
    }
    d[s]=0;
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int v=0;v<n;v++){
            if(M[u][v] == 0){
                continue;
            }
            if(d[v]!=INF){
                continue;
            }
        }
    // ここから 螺旋本P.285参照->このコードは中止
    }
}
