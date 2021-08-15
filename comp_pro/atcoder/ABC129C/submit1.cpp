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
    vector<bool> stair_broken(dpsize);
    vector<ll> stair_broke_point(dpsize);
    ll stair_num;
    ll break_sum;
    cin >> stair_num >> break_sum;
    for(ll &e:dp){
        e = default_comv;
    }
    for(ll j=0;j<dpsize;j++){
        stair_broken[j] = false;
    }
    for(ll &e:stair_broke_point){
        e = -1;
    }
    if(break_sum != 0){
        for(ll &e:stair_broke_point){
            cin >> e;
        }
        // 壊れている段にtrueのマークを付ける
    }

    dp[0] = 0;
    if(!stair_broken[1])dp[1] = 1;
    if(!stair_broken[2])dp[2] = 2;
    for(ll j=3;j<=stair_num;j++){
        dp[j] = dp[j-1] + dp[j-2];
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
