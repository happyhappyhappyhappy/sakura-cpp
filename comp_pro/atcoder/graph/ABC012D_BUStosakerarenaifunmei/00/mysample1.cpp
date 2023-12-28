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
const long long INF=1e17;

void warshall_floyd(vector<vector<long long>> &dist,vector<vector<long long>> &prev){
    int V=(int)dist.size();
    for(int k=0;k<V;k=k+1){
        for(int i=0;i<V;i=i+1){
            for(int j=0;j<V;j=j+1){
                long long x=dist[i][k]+dist[k][j];
                if(x < dist[i][j]){
                    dist[i][j]=x;
                    prev[i][j]=prev[k][j];
                }
            }
        }
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
    vector<vector<long long>> dist(V,vector<long long>(V,INF));
    vector<vector<long long>> prev(V);
    for(int j=0;j<V;j=j+1){
        dist[j][j]=0;
        prev[j]=vector<long long>(V,j);
    }
    for(int j=0;j<E;j=j+1){
        long long s,t,c;
        cin >> s >> t >> c;
        dist[s-1][t-1]=c;
        dist[t-1][s-1]=c;
    }
    // debug("---INPUT---\n");
    // for(int j=0;j<V;j=j+1){
    //     debug("%d : ",j);
    //     for(auto& e:dist[j]){
    //         if((INF>>1) < e){
    //             debug("INF ");
    //         }else{
    //             debug("%3lld ",e);
    //         }
    //     }
    //     debug("\n");
    // }
    warshall_floyd(dist,prev);
    // debug("---output---\n");
    // for(int j=0;j<V;j=j+1){
    //     debug("%d : ",j);
    //     for(auto& e:dist[j]){
    //         if((INF>>1)<e){
    //             debug("INF ");
    //         }else{
    //             debug("%3lld ",e);
    //         }
    //     }
    //     debug("\n");
    // }
    // 最悪の値の最小値
    long long ans=INF;
    for(int j=0;j<V;j=j+1){
        auto max_dist = std::max_element(dist[j].begin(), dist[j].end());
        long long max_dist_val=*max_dist;
//        cerr << j << " " << mindist2 << "\n" << flush;
        if( max_dist_val < ans){
            ans=max_dist_val;
        }
    }
    cout << ans << "\n" << flush;
    return 0;
}
