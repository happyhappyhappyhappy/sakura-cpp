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
    int N,M,R;
    cin >> N >> M >> R;
    int p_cnt=min(R,8);
    vector<int> plc(p_cnt,-1);
    for(int j=0;j<p_cnt;j=j+1){
        cin >> plc[j];
    }
    for(auto& e:plc){
        debug("%d ",e);
    }
    debug("\n");
    sort(plc.begin(),plc.end());
    for(auto& e:plc){
        debug("%d ",e);
    }
    debug("\n");
    do{

    }
    return 0;
}