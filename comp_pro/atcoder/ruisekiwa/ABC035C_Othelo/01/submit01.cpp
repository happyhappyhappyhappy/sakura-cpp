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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N,Q;
    cin >> N >> Q;
    vector<long long> p(N+2,0);
    vector<long long> acc(N+2,0);
    for(int j=0;j<Q;j=j+1){
        // いもす情報の入力
        int l,r;
        cin >> l >> r;
        p[l]=p[l]+1;
        p[r+1]=p[r+1]+1; // 再度めくるの意味 -1にしようしたが同じ方向だし
        // for(int k=1;k<=N;k++){
        //     debug("%lld ",p[k]);
        // }
        // debug("\n");
    }

    for(int j=0;j<=N;j=j+1){
        acc[j+1]=acc[j]+p[j+1];
        // for(int k=1;k<=N;k++){
        //     debug("%lld ",acc[k]);
        // }
        // debug("\n");
    }
    for(int j=1;j<=N;j=j+1){
        cout << (acc[j]%2) ;
        // if(j!=N){
        //     cout << "-";
        // }
    }
    cout << "\n" << flush;
    return 0;
}
