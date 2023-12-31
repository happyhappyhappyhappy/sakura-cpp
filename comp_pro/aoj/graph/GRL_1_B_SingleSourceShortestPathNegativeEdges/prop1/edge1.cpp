// Edgeデータを競技プログラミング風に入れる
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
    int source;
    int destination;
    int weight;
};
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    vector<Edge> Graph;
    int V,E;
    cin >> V >> E;
    for(int j=0;j<E;j=j+1){
        int s,d,w;
        cin >> s >> d >> w;
        Graph.push_back({s,d,w});
    }
    for(auto& e:Graph){
        debug("%d %d %d\n",e.source,e.destination,e.weight);
    }
    return 0;
}
