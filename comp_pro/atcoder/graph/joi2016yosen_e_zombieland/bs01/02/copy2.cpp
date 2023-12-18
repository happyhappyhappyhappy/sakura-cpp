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
const int inf = INT_MAX/2;
const ll infl = 1LL << 60;
template<typename T>using min_priority_queue = priority_queue<T,vector<T>,greater<T>>;
template<class T>bool chmin(T& a,const T& b)
                    {
                        if(b<a)
                        {
                            a=b;
                            return true;
                        }
                        return false;
                        }
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int N,M,K,S,P,Q;
vector<int> E[101010];
bool zombie[101010];
bool danger[101010];
int dist[101010];
void bfs(){
    queue<int> que;
    for(int j=0;j<N;j=j+1){
        if(zombie[j]==true){
            dist[j]=0;
            que.push(j);
        }
        else{
            dist[j]=-1;
        }
    }
    while(que.empty()==false){
        int cu = que.front();
        que.pop();
        for(auto to:E[cu]){
            if(dist[to]<0){
                dist[to]=dist[cu]+1;
                que.push(to);
            }
        }
    }
    for(int j=0;j<N;j=j+1){
        if( 1 <= dist[j] and dist[j] <= S){
            danger[j]=true;
        }
    }
}
bool vis[101010];
ll D[101010];
long long dijk(){
    for(int j=0;j<N;j=j+1){
        D[j]=infl;
    }
    for(int j=0;j<N;j=j+1){
        vis[j]=false;
    }
    min_priority_queue<pair<ll,int>> que;
    D[0]=0;
    que.push({0,0});
    while(que.empty()==false){
        auto q = que.top();
        que.pop();
        ll cst=q.first;
        int cu = q.second;
        if(cu == N-1){
            if(danger[cu]==true){
                return cst - Q;
            }else{
                return cst - P;
            }
        }
        if(vis[cu]==true){
            continue;
        }
        vis[cu]=true;
        for(auto to:E[cu]){
            if(zombie[to]==true){
                debug("都市 %d にて、都市 %d にはゾンビがいるので泊められない。スキップ。\n",cu,to);
                continue;
            }
            ll cst2=cst;
            if(danger[to]==true){
                cst2=cst2+Q;
            }else{
                cst2=cst2+P;
            }
            bool chminf=chmin(D[to],cst2);
            if(chminf == true){
                que.push({D[to],to});
            }
        }
    }
    return -1;
}
int main(void){
    initial();
    cin >> N >> M >> K >> S >> P >> Q;
    for(int j=0;j<K;j=j+1){
        int c;
        cin >> c;
        c=c-1;
        zombie[c]=true;
    }
    for(int j=0;j<M;j=j+1){
        int a,b;
        cin >> a >> b;
        a=a-1;
        b=b-1;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    bfs();
    ll ans=dijk();
    cout << ans << "\n" << flush;
    return 0;
}
