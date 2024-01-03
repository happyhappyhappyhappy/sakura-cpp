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
constexpr long long INF=(1LL<<60);
struct Edge{
    int from;
    int to;
    int cost;
};
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
bool BellmanFord(const vector<Edge>& edges,vector<ll>& distances,int startIndex){
    distances[startIndex]=0;
    for(int j=0;j<(int)distances.size();j=j+1){
        bool changed=false;
        for(const auto& edge: edges){
            if(distances[edge.from]==INF){
                continue;
            }
            else{
                ll x = distances[edge.from]+edge.cost;
                if(x < distances[edge.to]){
                    distances[edge.to]=x;
                    changed=true;
                }
            }
        }
        if(changed==false){
            return false;
        }
    }
    for(int j=0;j<(int)distances.size();j=j+1){
        for(const auto& edge:edges){
            if(distances[edge.from]==INF){
                continue;
            }
            ll x = distances[edge.from]+edge.cost;
            if(x < distances[edge.to]){
//                debug("頂点 %d は閉路の影響を受けると分かったので %lld をセット",edge.to+1,-INF);
                distances[edge.to]=-INF;
            }
        }
    }
    return true;
}
int main(void){
    initial();
    int V,E;
    cin >> V >> E;
    vector<Edge> edges;
    for(int j=0;j<E;j=j+1){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a-1,b-1,c*(-1)});
    }
    vector<ll> distances(V,INF);
    BellmanFord(edges,distances,0);
    ll ans=distances[V-1];
    if(ans==-INF){
        cout << "inf\n" << flush;
    }else{
        cout << ans*(-1) << "\n" << flush;
    }
    return 0;
}
