#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static ll DP_TABLE=100010;
static ll DP_MAX=1LL << 60;

template <type XXX> inline bool chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
        return true;
    }
    else{
        return false;
    }
    return false;
}

ll resolve(void){

    vector<ll> dp(DP_TABLE);

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll testcase=1;
    for(ll j=0;j < testcase; j++){
        cout << resolve() << "\n";
    }
    return 0;
}
