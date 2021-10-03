#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll ALLN=110;
ll ALLPT = ALLN*110;
vector<int> PT(ALLN); 
vector<vector<int>> DP(ALLN,vector<int>(ALLPT));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);
    for(ll j=0;j<ALLN;j++){
        for(ll k=0;k<ALLPT;k++){
            DP[j][k]=0;
        }
    }    
    DP[0][0] = 1;
}

int main(void){
    initial();
    ll n;
    cin >> n;
    for(ll &e:PT){
        cin >> e;
    }
    ll totalScore = 0;
    for(ll j=0;j<n;j++){
        totalScore = totalScore+PT[j];
    }
    // totalScoreに満点が置かれる
    for(ll j=0;j<n;j++){
        for(ll k=0;k<=totalScore;k++){
            if(a[j] > totalScore){
                // そのままkの値が移行される
                // しかし何か中途半端な気がする
                // TODO:ここをひとまずコーディング
            }
        }
    }
    return 0;
}