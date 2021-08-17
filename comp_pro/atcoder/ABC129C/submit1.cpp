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
// TODO: むやみに範囲For文を使うとややこしくなるので一旦消して書き直す
// 標準入力文のみ。
    for(ll &e:dp){
        e = default_comv;
    }
    for(ll j=0;j<dpsize;j++){
        stair_broken[j] = false;
    }
    for(ll &e:stair_broke_point){
        e = -1;
    }
    // check
    cout << "Line 35 is OK\n";
    if(break_sum != 0)
    {
        /** 
        for(ll &e:stair_broke_point)
        {
            cin >> e;
        }
        **/
        for(ll j=0;j<break_sum;j++)
        {
            ll e;
            cin >> e;
            cout << e << "\n";
            stair_broke_point[j] = e;
        }
        cout << "\nThis Line is OK\n";
        // TODO: ここから火種になっている感じ
        for(ll j=0;j<break_sum;j++){
            stair_broken[stair_broke_point] = true;
        }
        // TODO:　この4行正しくして確認する
        // もしかしたら true,falseは出ないかもしれない
        for(ll j=0;j<=stair_num;j++){
            
            cout << stair_broken[j] << "\t";
        }
        cout << "\n";
        /** for(ll &e:stair_broke_point)
        {
            stair_broken[e] = true;
        }
        **/
    }
    dp[0] = 0;
    if(stair_broken[1] == false){ // 一段目壊れてない
        dp[1] = 1; // 一通り
    }
    else{// 一段目壊れた
        dp[1] = 0; // 無し
    }
    dp[2] = dp[1] + 1;
    if(stair_broken[2] == true){
        dp[2] = 0;
    }
    

    for(ll j=3;j<=stair_num;j++){
        dp[j] = dp[j-1] + dp[j-2];
        if(stair_broken[j] == true){
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
