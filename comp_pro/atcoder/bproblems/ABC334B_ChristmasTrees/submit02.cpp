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
long long myfloat(long long a,long long b){
    long long result=0;
    long long d = (a%b+b)%b;
    result=(a-d)/b;
    return result;
}
long long solver(long long a,long long m,long long l,long long r){
    long long result=0;
    l = l - a;
    r = r - a;
    result = myfloat(r,m)-myfloat(l-1,m);
    return result;
}
int main(void){
    initial();
    long long a,m,l,r;
    cin >> a >> m >> l >> r;
    long long ans = solver(a,m,l,r);
    cout << ans << endl;
    return 0;
}
