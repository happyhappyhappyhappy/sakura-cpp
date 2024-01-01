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
const int INF=1000000000;
template<class XXX> bool chmin(XXX &x,XXX y){
    if(y < x){
        x = y;
        return true;
    }
    return false;
}
void floydWarshall(vector<vector<int>>& dist,int V){
    for(int p=0;p<V;p=p+1){
        for(int j=0;j<V;j=j+1){
            for(int k=0;k<V;k=k+1){
                if(dist[j][p]<INF && dist[p][k]<INF){
                    int x = dist[j][p]+dist[p][k];
                    chmin(dist[j][k],x);
                    // bool check=chmin(dist[j][k],x);
                    // if(check){
                    //     debug("%d -> %d を %d -> %d -> %d に変更しました\n",j,k,j,p,k);
                    // }
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
void print_dist(vector<vector<int>> &X){
    int N=(int)X.size();
    for(int j=0;j<N;j=j+1){
        for(int k=0;k<N;k=k+1){
            int x=X[j][k];
            if(x == INF){
                debug("INF ");
            }else{
                debug("%3d ",x);
            }
        }
        debug("\n");
    }
}
void print_r(vector<int>& X){
    debug("---経路---\n");
    int M = (int)X.size();
    for(int j=0;j<M;j=j+1){
        debug("%d ",X[j]);
    }
    debug("\n");
}
int main(void){
    initial();
    int N,M,R;
    cin >> N >> M >> R;
    vector<int> r;
    for(int j=0;j<R;j=j+1){
        int r0;
        cin >> r0;
        r.push_back(r0-1);
    }
    vector<vector<int>> dist(N,vector<int>(N,INF));
    for(int j=0;j<M;j=j+1){
        int a0,b0,c;
        cin >> a0 >> b0 >> c;
        dist[a0-1][b0-1]=c;
        dist[b0-1][a0-1]=c;
    }
    for(int j=0;j<N;j=j+1){
        dist[j][j]=0;
    }
    sort(r.begin(),r.end());
//    print_r(r);
//    debug("各距離\n");
//    print_dist(dist);
    floydWarshall(dist,N);
//    debug("ワーシャルフロイド法の結果\n");
//    print_dist(dist);
    int ans=INF;
    do{
//        print_r(r);
        int cost=0;
        for(int j=0;j<(int)r.size()-1;j=j+1){
            cost=cost+dist[r[j]][r[j+1]];
        }
//        debug("この場合は %d\n",cost);
//        bool check=chmin(ans,cost);
        chmin(ans,cost);
        // if(check){
        //     debug("更新しました\n");
        // }
    }while(next_permutation(r.begin(),r.end())==true);
    cout << ans << "\n" << flush;
    return 0;
}
