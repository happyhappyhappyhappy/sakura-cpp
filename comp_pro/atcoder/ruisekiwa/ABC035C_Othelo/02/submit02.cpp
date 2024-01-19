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
    vector<int> B(N+10,0);
    for(int j=0;j<Q;j=j+1){
        int l ;
        int r ;
        cin >> l >> r;
        B[l-1]=B[l-1]+1;
        B[r]=B[r]-1;
    }
    for(int j=1;j<N;j=j+1){
        B[j]=B[j]+B[j-1];
    }
    for(int j=0;j<N;j=j+1){
        cout << (B[j]&1);
    }
    cout << "\n" << flush;
    return 0;
}
