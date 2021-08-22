#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static ll dptable=35;
static ll default_comv=0;

ll solver(vector<ll>& dp,ll position){
    ll answer = 0;
    answer = (dp[position]+3650)/3650;
    return answer;
}
bool dp_init(vector<ll>& dp){
    bool result=true;
    for(ll j=0;j<dptable;j++){
        dp[j]=default_comv;
    }
    return result;
}
bool dp_process(vector<ll>& dp){
    bool result=true;
    dp[0] = 0;
    dp[1] = dp[0] + 1;
    dp[2] = dp[1] + 1;
    dp[3] = dp[2] + dp[1] + 1;
    for(ll j=4;j<=dptable;j=j+1){
        dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
     //   cout << j << "\t" << dp[j] << "\n";
    }
    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll input_data;
    vector<ll> dp(dptable);
    dp_init(dp);
    dp_process(dp);
    /**
    for(ll j=1;j<=10;j++){
        ll answer ;
        answer = solver(dp,j);
        cout << answer << "\n";
    }**/
    while(true){
        ll answer=0;
        cin >> input_data;
        if(input_data == 0){
            // 処理終了
            break;
        }
        answer = solver(dp,input_data);
        cout << answer << "\n";
    }
    return 0;
}
