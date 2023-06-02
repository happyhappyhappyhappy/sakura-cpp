#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
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
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll gcd(ll x,ll y){
    if(y == 0){
        debug("y == %dll のため x == %dll を返します",y,x);
        return x;
    }
    else{
        // TODO:2023-06-02 19:32:21 ここからスタート
        // 下のロジックを出力
        ll z = x % y;
        return gcd(y,x % y);
    }
}

int main(void){
    initial();
    int M=0;
    int N=0;
    cin >> M >> N;

    return 0;
}
