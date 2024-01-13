#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/lib/dump.hpp"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    vector<int> P(M,0);
    vector<int> Y(M,0);
    for(int j=0;j<M;j=j+1){
        cin >> P[j] >> Y[j];
        P[j]=P[j]-1;
    }
    vector<vector<int>> vals(N); // 2次元Vector
    for(int j=0;j<M;j=j+1){
        vals[P[j]].push_back(Y[j]);
    }
    // valsの中身
    debug("valsソート前\n");
    for(int j=0;j<N;j=j+1){
        debug("%d->",j);
        for(auto& x:vals[j]){
            debug("%d ",x);
        }
        debug("\n");
    }
    for(int j=0;j<N;j=j+1){
        sort(vals[j].begin(),vals[j].end());
        // 座標圧縮のパターン
        vals[j].erase(unique(vals[j].begin(),vals[j].end()),vals[j].end());
    }
    debug("valsソート後\n");
    for(int j=0;j<N;j=j+1){
        debug("%d->",j);
        for(auto& x:vals[j]){
            debug("%d ",x);
        }
        debug("\n");
    }
    cout << "元のソース\n" << flush;
    for(int j=0;j<M;j=j+1){
        cout << P[j] << "->" << Y[j] << "\n" << flush;
    }
    cout << "最終のソース\n" << flush;
    for(int j=0;j<M;j=j+1){
        int x=P[j];
        printf("%d->",x);
        int id=lower_bound(vals[x].begin(),vals[x].end(),Y[j])-vals[x].begin();
        printf("%d\n",id);
    }
    return 0;
}
