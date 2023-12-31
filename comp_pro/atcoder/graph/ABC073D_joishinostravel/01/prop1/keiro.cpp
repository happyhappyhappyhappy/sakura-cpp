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
    vector<int> r;
    for(int j=0;j<R;j=j+1){
        int r0;
        cin >> r0;
        r.push_back(r0-1);
    }
    vector<int> A;
    vector<int> B;
    for(int j=0;j<M;j=j+1){
        int a0,b0;
        cin >> a0 >> b0;
        A.push_back(a0-1);
        B.push_back(b0-1);
    }
    sort(r.begin(),r.end());
    int cnt=0;
    do{
        debug("--%d個目--\n",cnt+1);
        for(int j=0;j<(int)r.size()-1;j=j+1){
            debug("%d -> %d\n",r[j],r[j+1]);
        }
        cnt=cnt+1;
    }while(next_permutation(r.begin(),r.end())==true);
    return 0;
}
