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
const ll INF = 1LL<<50;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N,M;
    cin >> N >> M;
    const int NMAX=1000;
    const int MMAX=2000;
    int a[MMAX],b[MMAX];
    ll c[MMAX];
    for(int j=0;j<M;j=j+1){
        cin >> a[j] >> b[j] >> c[j];
        c[j]=c[j]*(-1);
    }
    ll dist[NMAX];
    for(int j=0;j<N;j=j+1){
        dist[j]=INF;
    }
    dist[0]=0;
    for(int loop=0;loop<N-1;loop=loop+1){
        for(int j=0;j<M;j=j+1){
            if(dist[a[j]-1]==INF){
                continue;
            }
            if(dist[a[j]-1]+c[j]<dist[b[j]-1]){
                dist[b[j]-1]=dist[a[j]-1]+c[j];
            }
        }
    }
    ll ans=dist[N-1];
    bool negative[NMAX];
    for(int j=0;j<N;j=j+1){
        negative[j]=false;
    }
    for(int loop=0;loop<N;loop=loop+1){
        for(int j=0;j<M;j=j+1){
            if(dist[a[j]-1]==INF){
                continue;
            }
            if(dist[a[j]-1]+c[j]<dist[b[j]-1]){
                dist[b[j]-1]=dist[a[j]-1]+c[j];
                negative[b[j]-1]=true;
                // debug("negative[%d]はtrueになりました\n",b[j]-1);
            }
            if(negative[a[j]-1]==true){
                // debug("negative[%d]がtrue->negative[%d]もtrue\n",a[j]-1,b[j]-1);
                negative[b[j]-1]=true;
            }
        }
    }
    if(negative[N-1]){
        cout << "inf\n" << flush;
    }else{
        cout << ans*(-1) << "\n" << flush;
    }
    return 0;
}
