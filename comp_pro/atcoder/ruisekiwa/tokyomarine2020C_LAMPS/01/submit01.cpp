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
int N; // ランプの数
int K; // 繰り返す回数
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> N >> K;
    vector<int> A(N+2,0); // バッファで2加えた だけ
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    for(int k=0;k<K;k=k+1){
        vector<int> B(N+2,0); // バッファで2加えただけ
        for(int j=0;j<N;j=j+1){
            int L = max(0,j-A[j]);
            int R = min(N-1,j+A[j]);
            B[L]=B[L]+1;
            B[R+1]=B[R+1]-1;// R=N-1になっても大丈夫
        }
        // 累積和
        for(int j=1;j<N;j=j+1){
            B[j]=B[j]+B[j-1];
        }
        bool same=true;
        for(int j=0;j<N;j=j+1){
            if(A[j]!=B[j]){
                same=false;
            }
            A[j]=B[j];
        }
        if(same==true){
            break;
        }
    }
    for(int j=0;j<N;j=j+1){
        if(j!=0){
            cout << " ";
        }
        cout << A[j];
    }
    cout << "\n" << flush;
    return 0;
}
