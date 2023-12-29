// どうやって合計を求めるかのテスト
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
void print(const vector<int>& plc){
    int cnt=(int)plc.size()-1;
    for(int j=0;j<cnt;j=j+1){
        debug("[%d]->[%d] ",plc[j],plc[j+1]);
    }
    debug("\n");
}
int main(void){
    initial();
    int N,M,R;
    cin >> N >> M >> R;
    int plc_cnt=min(R,8);
    vector<int> plc(plc_cnt);
    debug("---初期情報---\n");
    for(int j=0;j<plc_cnt;j=j+1){
        cin >> plc[j];
    }
    print(plc);
    debug("---ソート---\n");
    sort(plc.begin(),plc.end());
    print(plc);
    int cnt=1;
    do{
        debug("---%3d番目---\n",cnt);
        print(plc);
        cnt=cnt+1;
    }while(next_permutation(plc.begin(),plc.end())==true);
    return 0;
}
