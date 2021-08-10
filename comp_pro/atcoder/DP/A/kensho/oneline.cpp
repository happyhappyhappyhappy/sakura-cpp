#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
// #pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const long long INF_PLUS = 1LL << 60; 
    const long long  DP_TABLE = 100010;
    vector<long long> dp(DP_TABLE);
    vector<long long> height(DP_TABLE);
    for(long long j;j<DP_TABLE;j++){
        dp.at(j) = INF_PLUS;
    }
    dp.at(0) = INF_PLUS ;
    ll place;
    cin >> place;

    for(auto &e:height){
        cin >> e;
    }
    for(long long j = 0;j < place;j=j+1)
    {
        cout <<  height[j] << "\t";
    }
    cout << "\n";
    return 0;
}
