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
const ll INF=yamaMAX_LL;

void floydWarshall(vector<vector<ll>>& dist,int V){
    for(int p=0;p<V;p=p+1){
        for(int j=0;j<V;j=j+1){
            for(int k=0;k<V;k=k+1){
                if(dist[j][p] < INF && dist[p][k] < INF){
                    ll x = dist[j][p]+dist[p][k];
                    if(x < dist[j][k]){
                        dist[j][k]=x;
                    }
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
void printdist(vector<vector<ll>>& dist,int V){
    debug("-----\n");
    for(int j=0;j<V;j=j+1){
        for(auto& e:dist[j]){
            debug("%lld ",e);
        }
        debug("\n");
    }
    debug("-----\n");
}
int main(void){
    initial();
    int V,E;
    cin >> V >> E;
    vector<vector<ll>> dist(V,vector<ll>(V,INF));
    for(int j=0;j<V;j=j+1){
        dist[j][j]=0;
    }
    for(int j=0;j<E;j=j+1){
        int a,b;
        ll c;
        cin >> a >> b  >> c;
        a = a-1;
        b = b-1;
        c = c*(-1);
        dist[a][b]=c;
    }
    floydWarshall(dist,V);
    if(dist[V-1][V-1]<0){
        cout << "inf\n" << flush;
    }else{
        cout << dist[0][V-1]*(-1) << "\n" << flush;
    }
    return 0;
}
