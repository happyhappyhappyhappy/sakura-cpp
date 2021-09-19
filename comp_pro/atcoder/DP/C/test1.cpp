#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

templete<class XXX> inline bool changemax(XXX& x,XXX y){
    bool result=false;
    if(x < y){
        x = y;
        result = true;
    }
    return result;
}


// Global 変数(固定)
const ll MAX_DATE=100010;
const ll PATTARN = 3;
// DP絡み変数
vector<ll> DP[MAX_DATE][PATTARN];

// 本体。_mainは実際の算術関数
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // DPテーブル初期化
    for(int j=0;j<MAX_DATE;j++){
        for(int k=0;k<MAX_DATE;k++){
            DP[j][k] = 0;
        }
    }
    _main(void);
    return 0;
}

void _main(void){
    int N;
    cin >> N;
    for(int j=0;j<N;j++){
        for(int k=0;k<PATTARN;k++){
            cin >> DP[j][k];
        }
    }
    for(int taro_date=1;taro_date<N;taro_date=taro_date+1){
        // TODO: ここからスタート 2021/09/19 19:53
    }
}