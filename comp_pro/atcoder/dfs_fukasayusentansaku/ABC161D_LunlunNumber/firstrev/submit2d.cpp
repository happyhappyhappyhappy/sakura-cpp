/**
 * 基本的なdfs探索回答 (復習)
*/
#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#else
// #defind debug(...) 42
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
// グローバル変数
vector<long long> lun;

void initial(void){
    // ここではいきなり求めようとしない
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void dfs(ll x){
    if(3234566667 < x ){ // 3234566667 入力数 10000の時の値
    // if(1000 < x ){ // TEST
    return ;
    }
    else{
        lun.push_back(x);
        ll one_unit = x % 10;
        dfs(x*10+one_unit);
        // xの位置の位が9以外の場合は一つ追加する
        if(one_unit < 9){
            dfs(x*10+one_unit+1);
        }
        // xの一の位が0以外の場合は一つ引く
        if(0 < one_unit){
            dfs(x*10+one_unit-1);
        }
        return ;
    }
}
void makeLunLun(void){
    for(ll j=1;j<10;j=j+1){
        dfs(j);
    }
    sort(lun.begin(),lun.end());
    // int lun_size=int(lun.size());
    /**
    for(int j=0;j<lun_size;j=j+1){
        debug(" %4lld",lun[j]);
    }
    debug("\n");
    **/
}
int main(void){
    initial();
    makeLunLun();
    int N;
    cin >> N;
    cout << lun[N-1] << "\n" << flush;
    return 0;
}
