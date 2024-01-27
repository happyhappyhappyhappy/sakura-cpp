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
int solver(int X){
    int res=0;
    while(true){
        int check=X%2;
        if(check==0){
            res=res+1;
            X=X>>1;
        }else{
            // debug("%dは2で割れなかったので終了\n",X);
            break;
        }
    }
    return res;
}
int main(void){
    initial();
    int N;
    cin >> N;
    cout << solver(N) << "\n" << flush;
    return 0;
}
