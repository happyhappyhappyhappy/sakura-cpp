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
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int comb(int x){
    return (x*(x-1))/2;
}

void solver(int N,int K){
    int key=-1;
    for(int r=0;r<=N;r=r+1){
        int one_pattern=0;
        one_pattern=comb(r)+comb(N-r);
        if(one_pattern == K){
            key=r;
        }
    }
    if(key==-1){
        cout << "NO" << "\n" << flush;
        return;
    }
    cout << "YES" << "\n" << flush;
    for(int j=0;j<key;j=j+1){
        cout << "1 " << flush;
    }
    for(int j=key;j<N;j=j+1){
        cout << "-1 " << flush;
    }
    cout << "\n" << flush;
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    while(testcase--){
        // debug("---- testcase: %3d ----\n",testcase);
        int n;
        int k;
        cin >> n >> k;
        solver(n,k);
    }
    return 0;
}
