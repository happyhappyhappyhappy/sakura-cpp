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
// const int yamaMAX_INT = 1 << 29; <- 今回はIntが使える範囲ギリギリまで増やすのでこれは無し

const ll yamaMAX_LL = 1LL << 60;
int N;
int yamaMAX_INT;
vector<vector<int>> XORL;
vector<int> A;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    yamaMAX_INT=(1<<30)+1;
}
int solver(void){
    for(int ) // TODO: bit全探索実行の手引き2023-07-03 19:37:06
}
int main(void){
    initial();
    cin >> N;
    A.resize(N);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    cout << solver() << "\n" << flush;
    // cout << yamaMAX_INT << "\n" << flush;
    return 0;
}
