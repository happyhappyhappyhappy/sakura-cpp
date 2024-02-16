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
long long int pow2(long long int p,long long int n){
    long long int res=1;
    while(0<n){
        int flug=n&1;
        if(flug==1){
            res=res*p;
        }
        n=n>>1;
        p=p*p;
    }
    return res;
}
int main(void){
    initial();
    long long int x = pow2(10,18);
    cout << yamaMAX_LL << endl;
    cout << x << endl;
    int cnt=0;
    while(x%2==0){
        x=x/2;
        cnt=cnt+1;
    }
    cout << x << endl;
    cout << cnt << endl;
    return 0;
}
