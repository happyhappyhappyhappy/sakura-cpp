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
const int INF=INT_MAX>>1;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void warshall_floyd(vector<vector<int>> &dist,vector<vector<int>> &prev){
    int V=(int)dist.size();
    for(int k=0;k<V;k=k+1){
        for(int i=0;i<V;i=i+1){
            for(int j=0;j<V;j=j+1){
                int x=dist[i][k]+dist[k][j];
                if(x < dist[i][j]){
                    dist[i][j]=x;
                    prev[i][j]=prev[k][j];
                }
            }
        }
    }
}
int main(void){
    initial();
    int N,M,R;
    cin >> N >> M >> R;
    int plc_cnt=min(R,8);
    vector<int> plc(plc_cnt);
    for(int j=0;j<plc_cnt;j=j+1){
        cin >> plc[j];
    }
    sort(plc.begin(),plc.end());
    vector<vector<int>> dist(N+1,vector<int>(N+1,INF));
    vector<vector<int>> prev(N+1);
    for(int j=0;j<M;j=j+1){
        int f,t,c;
        cin >> f >> t >> c;
        dist[f][t]=c;
        dist[t][f]=c;
    }
    for(int j=1;j<=N;j=j+1){
        dist[j][j]=0;
        prev[j]=vector<int>(N+1,j);
    }
    warshall_floyd(dist,prev);
    int ans=INF;
    int plc_from=(int)plc.size()-1;
    int cnt=1;
    do{
        int nowd=0;
        for(int j=0;j<plc_from;j=j+1){
            int plc_valf=plc[j];
            int plc_valt=plc[j+1];
            nowd=nowd+dist[plc_valf][plc_valt];
        }
        if(nowd<ans){
            ans=nowd;
        }
        cnt=cnt+1;
    }while(next_permutation(plc.begin(),plc.end())==true);
    cout << ans << "\n" << flush;
    return 0;
}
