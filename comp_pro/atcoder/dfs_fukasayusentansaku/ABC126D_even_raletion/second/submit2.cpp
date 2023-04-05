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
using Edge=pair<int,ll>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(int &N,vector<vector<Edge> &G,vector<int> &c_code){
    for(int j=0;j<N;j=j+1){
        debug("根%5dについて関連している木\n",j);
        for(int k=0;k<(int)G[j].size();k=k+1){
            Edge e = G[j][k];
            int r=e.first;
            ll d=e.second;
            debug("  ",r,d); // TODO:ここからスタート
        }
    }

}

int main(void){
    initial();
    int N;
    cin >> N;
    G.assign(N,vector<Edge>());
    c_code.assign(N,0);
    for(int j=0;j<N-1;j=j+1){
        int from,to;
        ll dist;
        cin >> from >> to >> dist;
        from=from-1;
        to=to-1;
        G[to].push_back(Edge(from,dist));
        G[from].push_back(Edge(to,dist));
    }
    solve(N,G,c_code);
    for(int j=0;j<N;j=j+1){
        cout << c_code[j] << " ";
    }
    cout << "\n" << flush;
    return 0;
}

