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
    priority_queue<pair<int,string>> que;
    que.emplace(3,"aaa");
    que.emplace(1,"bbb");
    que.emplace(4,"ccc");
    que.emplace(3,"orere");
    while(que.empty()==false){
        pair<int,string> x;
        x = que.top();
        cout << x.first << "," << x.second <<"\n" << flush;
        que.pop();
    }
    return 0;
}
