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
    int N;
    cin >> N;
    vector<int> A(N,0);
    for(auto& a:A){
        cin >> a;
    }
    vector<int> B=A;
    sort(B.begin(),B.end());
    B.erase(unique(B.begin(),B.end()),B.end());
    // for(int j=0;j<(int)B.size();j=j+1){
    //     debug("%d\n",B[j]);
    // }
    vector<int> ans(N,0);
    for(int j=0;j<N;j=j+1){
        ans[j]=lower_bound(B.begin(),B.end(),A[j])-B.begin();
    }
    for(auto& x:ans){
        cout << x << "\n" << flush;
    }
    return 0;
}
