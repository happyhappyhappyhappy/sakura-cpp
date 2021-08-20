#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static ll dptable=35;
static ll default_comv=0;

bool dp_init(vector<ll>& dp){
    bool result=true;
    for(ll j=0;j<dptable;j++){
        dp[j]=default_comv;
    }
    return result;
}
bool dp_process(vector<ll>& dp){
    bool result=true;
    return result;
}

ll solver(vector<ll>& dp,ll input_data){
    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll input_data;
    vector<ll> dp(dptable);
    dp_init(dp);
    dp_process(dp);
    while(true){
        cin >> input_data;

    }

    return 0;
}
