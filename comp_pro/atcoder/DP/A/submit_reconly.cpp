#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll PLUS_MAX = 1LL<<60;
ll BOX_SIZE = 100010;
ll call_rec;


template<class XXX> inline bool chmin(XXX &x,XXX y){
    bool result = false;
    if(y < x){
        x = y;
        result = true;
    }
    return result;
}

ll rec(vector<ll> &dp,vector<ll> &height,ll nowPosition){

    ll result = PLUS_MAX;
    // if(dp.at(nowPosition) != PLUS_MAX){
    //    result = dp[nowPosition];
    //    return result;
    // }
    if(nowPosition == 0){
        result = 0;
        return result;
    }
    chmin(result,rec(dp,height,nowPosition-1)+
    abs(height.at(nowPosition)-height.at(nowPosition-1)));
    call_rec = call_rec + 2;
    if(1 < nowPosition){
    chmin(result,
    rec(dp,height,nowPosition-2)
    +abs(height[nowPosition-2]-height[nowPosition]));
    call_rec = call_rec + 2;
    }
    dp[nowPosition] = result;
    return result;
}

ll resolve(void){
    ll result = PLUS_MAX;
    vector<ll> dp(100010);
    vector<ll> height(100010);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll problem_size=0;
    cin >> problem_size;
    for (ll i = 0; i < BOX_SIZE; i++)
    {
        height[i] = PLUS_MAX;
    }
    for(ll i = 0;i<problem_size;i++){
        cin >> height[i];
    }
    for(ll j=0;j< BOX_SIZE;j++){
        dp[j] = PLUS_MAX;
    }   
    result = rec(dp,height,problem_size-1);
    return result;
}

int main(void)
{
    int testcase=1;
    for (int i = 0; i < testcase; i++)
    {   
        call_rec=0;
        cout << resolve() << "\n";
        cout << "recが呼ばれた回数\t" << call_rec << "\n";
    }
    
    return 0;
}
