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
using ll=long long int;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
ll solver(ll X,int &cnt2,int &cnt3){
    while(X%2==0){
        X=X/2;
        cnt2=cnt2+1;
    }
    while(X%3==0){
        cnt3=cnt3+1;
        X=X/3;
    }
    // debug("残った値は %lldです。これを返します。\n",X);
    return X;
}
int main(void){
    initial();
    ll x;
    cin >> x;
    int cnt2=0;
    int cnt3=0;
    if(solver(x,cnt2,cnt3)==1){
        cout << "Yes" << endl;
        // debug("2は %d 回,3は %d 回使いました。\n",cnt2,cnt3);
    }else{
        cout << "No" << endl;
    }
    return 0;
}
