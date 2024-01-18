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
int N;
int K;
vector<int> A(201010,0);
vector<int> B(201010,0);

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> N >> K;
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    for(int k=0;k<K;k=k+1){
        debug("ただいま %d 回目\n",k);
        for(int j=0;j<N;j=j+1){
            B[j]=0;
        }
        for(int j=0;j<N;j=j+1){
            debug("位置 %d について 今は強さは%d \n",j,A[j]);
            int L = max(0,j-A[j]);
            int R = min(N-1,j+A[j]);
            debug("区間 %d から %d まで +1するようにする\n",L,R);
            B[L]=B[L]+1;
            B[R+1]=B[R+1]-1;
        }
        debug("%d 回目 累積和前\n",k);
        for(int j=0;j<N;j=j+1){
            if(j!=0){
                debug(" ");
            }
            debug("%d",B[j]);
        }
        debug("\n");
        for(int j=1;j<N;j=j+1){
            B[j]=B[j]+B[j-1];
        }
        debug("%d 回目 累積和後\n",k);
        for(int j=0;j<N;j=j+1){
            if(j!=0){
                debug(" ");
            }
            debug("%d",B[j]);
        }
        debug("\n");
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
