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
template<typename T>
struct Edge{
    int to;
    T cost;
};
using Graph=vector<vector<Edge<long long>>>;
const long long INF = (1LL<<60);
template<typename T>
void dijkstra(const Graph &G,int s,vector<T> &dis,vector<int> &prev){
    using P = pair<T,int>;
    int N = G.size();
    dis.resize(N,INF);
    prev.resize(N,-1);
    priority_queue<P,vector<P>,greater<P>> pq;
    dis[s]=0;
    pq.emplace(dis[s],s);
    while(pq.empty()==false){
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if(dis[v] < p.first){
            continue;
        }
        for(auto &e: G[v]){
            long long x = dis[v]+e.cost;
            if(x < dis[e.to]){
                dis[e.to]=x;
                prev[e.to]=v;
                pq.emplace(dis[e.to],e.to);
            }
        }
    }
}
vector<int> get_path(const vector<int> &prev,int t){
    vector<int> path;
    for(int cur=t;cur!=-1;cur=prev[cur]){
        path.push_back(cur);
    }
    reverse(path.begin(),path.end());
    return path;
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int V,E,r;
    cin >> V >> E >> r;
    Graph G(V);
    for(int j=0;j<E;j=j+1){
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b,c});
    }
    for(int j=0;j<V;j=j+1){
        for(auto &e:G[j]){
            debug("頂点 %d->%d,コスト %lld\n",j,e.to,e.cost);
        }
    }
    vector<long long> dis;
    vector<int> prev;
    dijkstra(G,r,dis,prev);
    for(int j=0;j<V;j=j+1){
        long long value=dis[j];
        if(value == INF){
            cout << "INF\n" << flush;
        }else{
            cout << value << "\n" << flush;
        }
    }
    return 0;
}