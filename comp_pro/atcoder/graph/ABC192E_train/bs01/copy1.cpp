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
typedef long long ll;
const ll infl = 1LL << 60;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
int N,M,X,Y;
int A[101010],B[101010],T[101010],K[101010];
vector<pair<int,pair<int,int>>> E[101010];
template<typename T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>bool chmin(T&a , const T& b){
    if(b<a){
        a = b;
        return true;
    }
    return false;
}
int vis[101010];
ll D[101010];
ll dijkstra(){
    for(int j=0;j<N;j=j+1){
        D[j]=infl;
    }
    for(int j=0;j<N;j=j+1){
        vis[j]=0;
    }
    min_priority_queue<pair<ll,int>> que;
    D[X]=0;
    que.push({0,X});
    while( que.empty()==false){
        auto q = que.top();
        que.pop();
        ll cst=q.first;
        int cu = q.second;
        if(cu==Y){
            return D[Y];
        }
        if(vis[cu]!=0){
            continue;
        }
        vis[cu]=1;
        for(auto p:E[cu]){
            int to=p.first;
            int T=p.second.first;
            int K = p.second.second;
            ll cst2=((cst+K-1)/K)*K+T;
            if(chmin(D[to],cst2)==true){
                debug("駅 %d に向かって 時刻 %lld に合わせます\n",to,D[to]);
                que.push({D[to],to});
            }
        }
    }
    return -1;
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> N >> M >> X >> Y;
    X = X-1;
    Y = Y-1;
    for(int j=0;j<M;j=j+1){
        cin >> A[j] >> B[j] >> T[j] >> K[j];
        A[j]=A[j]-1;
        B[j]=B[j]-1;
        E[A[j]].push_back({B[j],{T[j],K[j]}});
        E[B[j]].push_back({A[j],{T[j],K[j]}});
    }
    ll ans = dijkstra();
    cout << ans << "\n" << flush;
    return 0;
}
