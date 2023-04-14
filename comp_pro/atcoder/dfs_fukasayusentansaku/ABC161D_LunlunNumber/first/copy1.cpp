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
const ll resultMAX=3234566667;
// 大域変数
vector<ll> lun(10001);// サンプルではここに全部放り込む
int K;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(ll N=1;N<=9;N=N+1){
    dfs(N);
    }

}
void dfs(ll X){

}
int main(void){
    initial();
    cin >> K;
    return 0;
}
