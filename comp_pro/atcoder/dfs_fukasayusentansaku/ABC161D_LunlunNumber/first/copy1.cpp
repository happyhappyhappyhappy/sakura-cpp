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
vector<ll> lun;// サンプルではここに全部放り込む
int K;
void dfs(ll X){
    if(X > resultMAX){
        return ;
    }
    lun.push_back(X);
    ll lastNum=X%10;
    dfs(X*10+lastNum); // 同じ数はOK
    if(lastNum !=9){
        dfs(X*10+(lastNum+1)); // 9でなければ1多くしてもOK
    }
    if(lastNum != 0){
        dfs(X*10+(lastNum-1)); // 0で無ければ1少なくしてOK
    }
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(ll N=1;N<=9;N=N+1){
    dfs(N);
    }
    sort(lun.begin(),lun.end()); // 整える
}
int main(void){
    initial();
    cin >> K;
    cout << lun[K-1] << "\n" << flush;
    return 0;
}
