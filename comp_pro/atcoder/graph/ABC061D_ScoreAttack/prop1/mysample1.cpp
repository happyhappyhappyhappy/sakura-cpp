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
constexpr long long INF = (1LL << 60);
struct Edge{
    int from;
    int to;
    ll cost;
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
        for(auto& edge:edges){
            if(distances[edge.from]==INF){
                continue;
            }
            ll d = distances[edge.from]+edge.cost;
            if(d < distances[edge.to]){
                distances[edge.to]=d;
                changed=true;
            }
        }
        if(changed==false){
            return false;
        }
    }
    for(int j=0;j<(int)distances.size();j=j+1){
        for(auto& edge:edges){
            if(distances[edge.from]==INF){
                continue;
            }
            ll d=distances[edge.from]+edge.cost;
            if(d<distances[edge.to]){
                distances[edge.to]=INF*(-1);
            }
        }
    }
    return true;
}
int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for(int j=0;j<M;j=j+1){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        edges[j].from=a-1;
        edges[j].to=b-1;
        edges[j].cost=c*(-1);
    }
    vector<ll> dist(N,INF);
    BellmanFord(edges,dist,0);
    if(dist[N-1]==(-1)*INF){
        cout << "inf\n" << flush;
    }else{
        cout << (-1)*dist[N-1] << "\n" << flush;
    }
    return 0;
}
