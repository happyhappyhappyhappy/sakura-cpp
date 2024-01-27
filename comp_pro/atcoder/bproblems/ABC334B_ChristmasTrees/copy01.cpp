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
long long myfloor(long long a,long long b)
{
    long long ans;
    // ans = (a+b-1)/b;
    long long d = (a % b + b)%b; // これで余りになる情報が求められる。
    ans = (a-d) / b;
    long long myans = a/b;
    debug("%lld を %lld で 割った時の書き下げ 模範 %lld 私 %lld\n",a,b,ans,myans);
    debug("配慮した誤差は %lldでした。\n",d);
    return ans;
}
int main(void){
    initial();
    long long a,m,l,r;
    cin >> a >> m >> l >> r;
    l=l-a;
    r = r-a;
    long long leftpos=myfloor(l-1,m);
    long long rightpos=myfloor(r,m);
    cout << rightpos - leftpos << "\n" << flush;
    return 0;
}
