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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void warshall_floyd(vector<vector<long long>> &dist,vector<vector<long long>> &prev){
    int V=(int)dist.size();
    for(int k=0;k<V;k=k+1){
        for(int i=0;i<V;i=i+1){
            for(int j=0;j<V;j=j+1){
                long long x = dist[i][k]+dist[k][j];
                if(x < dist[i][j]){
                    // debug("%d->%dの値置き換え\n",i,j);
                    dist[i][j]=x;
                    // debug("途中で%dに寄り道\n",k);
                    prev[i][j]=prev[k][j];
                }
            }
        }
    }
}
bool is_negative(const vector<vector<long long>> &dist){
    int V = (int)dist.size();
    for(int j=0;j<V;j=j+1){
        if(dist[j][j]<0){
            return true;
        }
    }
    return false;
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
        dist[s][t]=c;
    }
    // debug("---INPUT---\n");
    // for(int j=0;j<V;j=j+1){
    //     debug("%d : ",j);
    //     for(auto& e:dist[j]){
    //         if(e == INF){
    //             debug("INF ");
    //         }else{
    //             debug("%3lld ",e);
    //         }
    //     }
    //     debug("\n");
    // }
    warshall_floyd(dist,prev);
    if(is_negative(dist)){
        cout << "NEGATIVE CYCLE\n" << flush;
    }else{
        for(int j=0;j<V;j=j+1){
            for(int k=0;k<V;k=k+1){
                if((INF>>1) <= dist[j][k]){
                        cout << "INF";
                }else{
                    cout << dist[j][k] ;
                }
                if(k!=V-1){
                    cout << " ";
                }
            }
            cout << "\n" << flush;
        }
    }
    return 0;
}