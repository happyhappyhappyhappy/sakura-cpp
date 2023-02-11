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

// TODO: ここの実装化
void dfs(int now,int before,vector<int> &val){

}

int main(void){
    initial();
    int N,Q;
    cin >> N >> Q;
    G.resize(N,vector<int>());
    for(int j=0;j<N-1;j=j+1){
        int point1,point2;
        cin >> point1 >> point2;
        debug(point1);
        debug(point2);
        point1 = point1 - 1;
        point2 = point2 - 1;
        debug1("%d に %dを入れました\n",point1,point2);
        debug1("%d に %dを入れました\n",point2,point1);
        G[point1].push_back(point2);
        G[point2].push_back(point1);
    }

    for(int j=0;j<N;j=j+1){
        debug1(" %d:",j);
        for(int k=0;k < (int)G[j].size();k=k+1){
            debug1(" %d",G[j][k]);
        }
        debug1(" \n");
    }
    vector<int> val(N,0);
    for(int j=0;j<Q;j=j+1){
        int n,q;
        cin >> n >> q;
        n = n-1;
        val[n]=val[n]+q;
    }
    debug(val);
    return 0;
}

