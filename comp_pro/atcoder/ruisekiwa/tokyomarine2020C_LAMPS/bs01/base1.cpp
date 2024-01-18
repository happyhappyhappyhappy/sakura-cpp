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
    int N,K;
    cin >> N >> K;
    vector<int> A(N,0);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    for(int j=0;j<K;j=j+1){
        vector<int> B(N,0);
        for(int k=0;k<N;k=k+1){
            debug("位置 %dで調査\n",k);
            debug("%d 回目 k-A[k]の値 %d これと 0の大きい方をleft変数にセット\n",j,k-A[k]);
            int left=max(0,k-A[k]);
            debug("left=%d\n",left);
            debug("%d 回目 k+A[k]の値 %d これと N-1の小さい方をright変数にセット\n",j,k+A[k]);
            int right=min(N-1,k+A[k]);
            debug("right=%d\n",right);
            B[left]=B[left]+1;
            if(right+1<N){
                B[right]=B[right]-1;
            }
            debug("Bのリスト(累積和前)\n");
            for(auto& b:B){
                debug("%d ",b);
            }
            debug("\n");
        }
        for(int x=1;x<N;x=x+1){
            B[x]=B[x]+B[x-1];
        }
        debug("Bのリスト(累積和後)\n");
        for(auto& b:B){
            debug("%d ",b);
            }
        debug("\n");
        for(int k=0;k<N;k=k+1){
            A[k]=B[k];
        }
    }
    return 0;
}
