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
    priority_queue<int> q0;
    q0.emplace(3);
    q0.emplace(1);
    q0.emplace(4);
    auto q=q0;
    int counter=1;
    debug("1回目\n");
    while(q.empty()==false){
        int x=q.top();
        q.pop();
        debug("No.%d->%d\n",counter,x);
        counter=counter+1;
    }
    q0.emplace(-2);
    q0.emplace(10);
    q = q0;
    counter=1;
    debug("2回目\n");
    while(q.empty()==false){
        int x=q.top();
        q.pop();
        debug("No.%d->%d\n",counter,x);
        counter=counter+1;
    }
    return 0;
}
