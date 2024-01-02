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
const ll INF=1LL<<50;
struct Edge{
    int source,destination;
    ll weight;
};
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
bool BellmanFord(vector<Edge>& edges,vector<ll>& dist,int V,int start){
    dist[start]=0;
    vector<bool> neg(V,false);
    for(int j=0;j<V-1;j=j+1){
        for(const Edge& e:edges){
            int u = e.source;
            int v = e.destination;
            ll w = e.weight;
            if(dist[u]!=INF){
                ll x = dist[u]+w;
                if(x < dist[v]){
                    dist[v]=x;
                }
            }
        }
    }
    for(int j=0;j<V-1;j=j+1){
        for(const Edge& e:edges){
            int u=e.source;
            int v=e.destination;
            ll w = e.weight;
            if(dist[u]!=INF){
                if(dist[u]+w<dist[v]){
                    neg[v]=true;
                }
            }
            if(neg[u]==true){
                neg[v]=true;
            }
        }
    }
    return neg[V-1];
}

int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for(int j=0;j<M;j=j+1)
    {
        int a,b;
        ll c;
        cin >> a >> b >> c;
        edges[j].source=a-1;
        edges[j].destination=b-1;
        edges[j].weight=c*(-1);
    }
    vector<ll> dist(N,INF);
    bool infChk=BellmanFord(edges,dist,N,0);
    if(infChk){
        cout << "inf" << "\n" << flush;
    }else{
        ll ans=dist[N-1]*(-1);
        cout << ans << "\n" << flush;
    }
    return 0;
}
