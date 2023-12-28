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
    int to;
    long long cost;
};
using Graph=vector<vector<Edge>>;
const long long INF = (1LL<<60);
void dijkstra(const Graph &G,int s,vector<long long> &dis,vector<int> &prev){
    using P = pair<long long,int>;
    int N = (int)G.size();
    dis.assign(N,INF);
    prev.assign(N,-1);
    priority_queue<P,vector<P>,greater<P>> pq;
    dis[s]=0;
    pq.emplace(dis[s],s);
    // for(int j=0;j<(int)dis.size();j=j+1){
    //     if(dis[j] == INF){
    //         debug("%d is 限界値\n",j);
    //     }else{
    //         debug("%d is %lld\n",j,dis[j]);
    //     }
    // }
    while(pq.empty()==false){
        P p = pq.top();
        pq.pop();
        int v=p.second;
        if(dis[v]<p.first){
            continue;
        }
        for(auto &e:G[v]){
            long long x = dis[v]+e.cost;
            if(x < dis[e.to]){
                dis[e.to]=x;
                prev[e.to]=v;
                pq.emplace(dis[e.to],e.to);
            }
        }
    }
    // for(int j=0;j<N;j=j+1){
    //     debug("町 %d: ",j);
    //     for(auto &e:G[j]){
    //         long long cst=e.cost;
    //         debug("%d is ",e.to);
    //         if(cst == INF){
    //             debug("通行不可 ");
    //         }else{
    //             debug("%lld ",cst);
    //         }
    //     }
    //     debug("\n");
    // }

}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int N,K;
    cin >> N >> K;
    vector<long long> pay;
    vector<int> range;
    vector<vector<int>> Gm(N);
    for(int j=0;j<N;j=j+1){
        long long p;
        int r;
        cin >> p >> r;
        pay.push_back(p);
        range.push_back(r);
    }
    for(int j=0;j<K;j=j+1){
        int frm,t;
        cin >> frm >> t;
//        debug("%d %d\n",frm,t);
        Gm[frm-1].push_back(t-1);
        Gm[t-1].push_back(frm-1);
    }
//    debug("-----入力情報-----\n");
    // for(int j=0;j<N;j=j+1){
    //     debug("<町 %d>\n",j);
    //     debug("タクシー運賃 %lld , 可動範囲 %d\n",pay[j],range[j]);
    //     debug("接続町 ");
    //     for(int k=0;k<(int)Gm[j].size();k=k+1){
    //         debug("%d ",Gm[j][k]);
    //     }
    //     debug("\n");
    // }
// bfsで相対位置の検索
    vector<vector<int>> D(N,vector<int>(N,-1));
    for(int j=0;j<N;j=j+1){
        queue<int> que;
        D[j][j]=0;
        que.push(j);
        while(que.empty()==false){
//            debug("現在のqueの数 %d",(int)que.size());
            int pos=que.front();
            que.pop();
            for(int k=0;k<(int)Gm[pos].size();k=k+1){
                int nextpos=Gm[pos][k];
                if(D[j][nextpos]!=-1){
                    continue;
                }else{
                    que.push(nextpos);
                    D[j][nextpos]=D[j][pos]+1;
                }
            }
        }
//        debug("\n");
    }
    // for(int j=0;j<N;j=j+1){
    //     debug("町 %d 発:",j);
    //     for(int k=0;k<N;k=k+1){
    //         debug(" %d",D[j][k]);
    //     }
    //     debug("\n");
    // }
    Graph G(N);
    for(int j=0;j<N;j=j+1){
        for(int k=0;k<N;k=k+1){
            long long cost=INF;
            if(D[j][k] <= range[j]){
                cost=pay[j];
            }
            G[j].push_back({k,cost});
        }
    }
    // for(int j=0;j<N;j=j+1){
    //     debug("町 %dから ",j);
    //     for(auto &e:G[j]){
    //         int city=e.to;
    //         long long payment=e.cost;
    //         debug("%d->",city);
    //         if(payment==INF){
    //             debug("不可 ");
    //         }else{
    //             debug("%lld ",payment);
    //             }
    //     }
    //     debug("\n");
    // }
    vector<long long> dist(N);
    vector<int> prev(N);
    dijkstra(G,0,dist,prev);
    cout << dist[N-1] << "\n" << flush;
    return 0;
}
