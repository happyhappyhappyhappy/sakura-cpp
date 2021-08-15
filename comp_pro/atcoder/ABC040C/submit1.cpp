#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static ll DP_TABLE=100010;
static ll DP_MAX=1LL << 60;

template <typename XXX> inline bool chmin(XXX &x,XXX y){
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
    ll result = 0;
    ll position ;
    cin >> position;
    vector<ll> DP(DP_TABLE);
    vector<ll> HEIGHT(DP_TABLE);
    for(ll &input_data:DP){
        input_data=DP_MAX;
    }
    DP[0]=0;
    for(ll &input_data:HEIGHT){
        cin >> input_data;
    }
    for(ll j=0;j<position;j++){
        chmin(DP[j+1],DP[j]+abs(HEIGHT[j]-HEIGHT[j+1]));
        chmin(DP[j+2],DP[j]+abs(HEIGHT[j+2]-HEIGHT[j]));
    }
    result = DP[position-1];
    return result;

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
