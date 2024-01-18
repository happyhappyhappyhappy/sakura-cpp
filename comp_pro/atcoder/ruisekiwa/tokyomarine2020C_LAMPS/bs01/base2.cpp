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
    for(auto& a:A){
        cin >> a;
    }
    for(int j=0;j<K;j=j+1){
            vector <int> B(N,0);
            for(int i=0;i<N;i++)
                {
                    int l = max(0,i-A[i] );
                    int r=min(N-1,i+A[i]);
                    B[l]++;
                    if (r+1<N) B[r+l]--;
                }
            debug("B %d 回目 累積和前\n",j);
            for(auto& b:B){
                debug("%d ",b);
            }
            debug("\n");
            for(int i=1;i<N;i++) B[i] +=B[i]+B[i-1];
            debug("B %d 回目 累積和後\n",j);
            for(auto& b:B){
                debug("%d ",b);
            }
            debug("\n");

        }
    return 0;
}
