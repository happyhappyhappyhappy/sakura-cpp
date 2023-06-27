#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
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
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
int N,M,Q;
int A[10];
int ans=0;
vector<int> a,b,c,d;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void allResize(int X){
    a.resize(X);
    b.resize(X);
    c.resize(X);
    d.resize(X);
}

void dfs(int cu,int lst){
    if(cu == N){
        debug("---ただ今のA---\n");
        for(int j=0;j<N;j=j+1){
            debug(" %3d",A[j]);
        }
        debug("\n");
        int total=0;
        for(int j=0;j<Q;j=j+1){
            int bj=b[j];
            int aj=a[j];
            if(A[bj]-A[aj]==c[j]){
                total=total+d[j];
            }
        }
        debug("total=%3d これをans=%3dに照合します\n",total,ans);
        chmax(ans,total);
        return;
    }
    for(int nxt=lst;nxt<M+1;nxt=nxt+1){
        A[cu]=nxt;
        debug("A[%3d]=%3d\n",cu,nxt);
        debug("dfs(%3d,%3d)\n",cu+1,nxt);
        dfs(cu+1,nxt);
    }
}
int main(void){
    initial();
    cin >> N >> M >> Q;
    allResize(Q);
    for(int j=0;j<Q;j=j+1){
        cin >> a[j] >> b[j] >> c[j] >> d[j];
        a[j]=a[j]-1;
        b[j]=b[j]-1;
    }
    dfs(0,1);
    cout << ans << "\n" << flush;
    return 0;
}
