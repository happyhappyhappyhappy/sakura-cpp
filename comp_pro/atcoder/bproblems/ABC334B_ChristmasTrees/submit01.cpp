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
long long solver(long long A,long long M,long long L,long long R){
    long long ans=0;
    long long first=(R-A)/M;
    long long second=((L-A)+M-1)/M;
    long long data=first-second+1;
    ans=max(0LL,data);
    return ans;
}
int main(void){
    initial();
    long long A,M,L,R;
    cin >> A >> M >> L >> R;
    cout << solver(A,M,L,R) << "\n" << flush;
    return 0;
}
