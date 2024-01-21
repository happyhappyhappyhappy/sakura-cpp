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
    int N,M;
    vector<int> A(100010,0);
    cin >> N >> M;
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    long long ans=0;
    long long sm = 0;
    unordered_map<int,int> cnt;
    cnt[0]=1;
    for(int j=0;j<N;j=j+1){
        sm=sm+A[j];
        long long sumM=sm%M;
        debug("j=%dの時 sum=%lld sumM=%lld\n",j,sm,sumM);
        ans=ans+cnt[sumM];
        cnt[sumM]=cnt[sumM]+1;
    }
    cout << ans << "\n" << flush;
    return 0;
}
