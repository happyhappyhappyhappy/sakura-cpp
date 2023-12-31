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
struct Edge{
    int source,destination,weight;
};
// ?? numBertices
void BellmanFord(vector<Edge>& edges,int numVertices,int source){
    vector<int> distance(numVertices,INT_MAX);
    distance[source]=0;
    for(int j=1;j<numVertices;j=j+1){
        for(const Edge& edge:edges){
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if(distance[u] != INT_MAX && distance[u]+w<distance[v]){
                distance[v]=distance[u]+w;
            }
        }
    }
    for(const Edge& edge:edges){
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;
        if(distance[u]!=INT_MAX && distance[u]+w<distance[v]){
            cout << "負の重みサイクルが存在します" << "\n" << flush;
            return;
        }
    }
    for(int j=0;j<numVertices;j=j+1){
        cout << "頂点 " << j << "への最短距離: " << distance[j] << "\n" << flush;
    }
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int V,E;
    cin >> V >> E;
    vector<Edge> Graph;
    for(int j=0;j<E;j=j+1){
        int s,d,w;
        cin >> s >> d >> w;
        Graph.push_back({s,d,w});
    }
    // for(auto& e:Graph){
    //     debug("始点 %d->終点 %d:コスト %d\n",e.source,e.destination,e.weight);
    // }
    int source = 0;
    BellmanFord(Graph,V,source);
    return 0;
}
