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
using Graph=vector<vector<int>>;
Graph G;


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfs(int v,int p,vector<int> &val){
    if(p != -1){
        val[v]=val[v]+val[p];
    }
    for(int j=0;j<(int)G[v].size();j=j+1){
        int next = G[v][j];
        if(next == p){
            // 親ノードから来た処理は実行しない。
            // 複数ノードから来ることはないので一つのみ
            continue;
        }
        else{
            dfs(next,v,val);
        }
    }
}

int main(void){
    initial();
    int N,Q;
    cin >> N >> Q;
    G.resize(N,vector<int>());
    for(int j=0;j<N-1;j=j+1){
        int point1,point2;
        cin >> point1 >> point2;
        point1 = point1 - 1;
        point2 = point2 - 1;
        G[point1].push_back(point2);
        G[point2].push_back(point1);
    }
    vector<int> val(N,0);
    for(int j=0;j<Q;j=j+1){
        int n,q;
        cin >> n >> q;
        n = n-1;
        val[n]=val[n]+q;
    }
    dfs(0,-1,val);
    for(int j=0;j<(int)val.size();j=j+1){
        cout << val[j] << " " ;
    }
    cout << "\n" << flush;
    return 0;
}

