#include<bits/stdc++.h>
#ifdef LOCAL
// #include<debug/debug.h>
// #include <debug/tdebug.h>
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/comp_pro/debug.h"
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
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N;
    cin >> N;
    vector<int> M;
    for(int j=0;j<N;j=j+1){
        int nn;
        cin >> nn;
        M.push_back(nn);
    }
    debug("----与えられたList----\n");
    for(auto &a:M){
        debug(" %d",a);
    }
    debug("\n");
    int x = *(min_element(M.begin(),M.end()));
    debug("最小値 :  %d\n",x);
    return 0;
}
