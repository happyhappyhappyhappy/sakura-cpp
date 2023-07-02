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
const ll yamaMAX_LL = 1LL << 60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    vector<int> bv={1,2,3,4,5,6};
    vector<int> av=bv;
    av.push_back(7);
    cout << "---bv---\n";
    for(auto &t:bv){
        cout << t << " ";
    }
    cout << "\n" << flush;
    cout << "---av---\n";
    for(auto &t:av){
        cout << t << " ";
    }
    cout << "\n" << flush;
    debug("bvのメモリアドレス %p\navのメモリアドレス%p\n"
    ,(void*)&bv,(void*)&av);
    return 0;
}
