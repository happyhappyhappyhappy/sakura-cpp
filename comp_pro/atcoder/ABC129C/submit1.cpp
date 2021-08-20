#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static ll dpsize=100010;
static ll modnum=1000000007;
static ll default_comv=0;


ll resolve(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll result=0;
    vector<long long> dp(dpsize);
    vector<int> stair_broken(dpsize);
    vector<ll> stair_broke_point(dpsize);
    ll stair_num;
    ll break_sum;
    cin >> stair_num >> break_sum;
    for(ll j=0;j<dpsize;j++){
        dp[j] = default_comv;
    }
    for(ll j=0;j<dpsize;j++){
        stair_broken[j] = 0;
    }
    for(ll j=0;j<dpsize;j++){ 
        stair_broke_point[j]=-1;
    }
    if(break_sum != 0)
    {
        for(ll j=0;j<break_sum;j++)
        {
            ll e;
            cin >> e;
//            cout << e << "\n";
            stair_broke_point[j] = e;
        }
        for(ll j=0;j<break_sum;j++){
            stair_broken[stair_broke_point[j]] = 1;
        }
    }
    dp[0] = 0;
    if(stair_broken[1] == 0){ // 一段目壊れてない
        dp[1] = 1; // 一通り
    }
    else{// 一段目壊れた
        dp[1] = 0; // 無し
    }
    dp[2] = dp[1] + 1;
    if(stair_broken[2] == 1){
        dp[2] = 0;
    }
    

    for(ll j=3;j<=stair_num;j++){
        dp[j] = (dp[j-1] + dp[j-2]) % modnum;
        if(stair_broken[j] == 1){
        dp[j] = 0;
        }
    }
    
    result = dp[stair_num];
    return result;
}

int main(int argc, char const *argv[])
{
    int testcase=1;
    for(int j=0;j<testcase;j++){
        cout << resolve() << '\n';
    }
    return 0;
}
