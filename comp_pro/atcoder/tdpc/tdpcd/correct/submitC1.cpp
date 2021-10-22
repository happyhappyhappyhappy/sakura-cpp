#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using dd=double;
// selecterの模範解答ベースで作成
// https://atcoder.jp/contests/tdpc/submissions/1813122

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}

map<ll,ll> primeFact(ll D){
    map<ll,ll> result;
    for(ll j=2LL;j*j<=D;j++){
        while(D%j == 0LL){
            result[j] = result[j]+1;
            D = D / j;
        }
    }
    // キレイに2,3,5の倍数だけで成り立っている物でなければその値を入れる
    if(D != 1LL){
        result[D] = 1LL;
    }
    return result;
}

int main(void){
    ll N;
    ll D;
    cin >> N >> D;
    map<ll,ll> baseMap=primeFact(D);
    /**
    map<ll,ll>::iterator it=baseMap.begin();
    while(it!=baseMap.end()){
        cout << it->first << " :: " << it->second << "\n";
        it++;
    }
    **/
    map<ll,ll> diceChecker = baseMap;
    /**
    map<ll,ll>::iterator it=diceChecker.begin();
    while(it!=diceChecker.end()){
        cout << it->first << " :: " << it->second << "\n";
        it++;
    }
    **/
    diceChecker.erase(2);
    map<ll,ll>::iterator it=diceChecker.begin();
    while(it!=diceChecker.end()){
        cout << it->first << " :: " << it->second << "\n";
        it++;
    }
    // TODO: もし2,3,5の要素がそもそも無かったらどうなるか調べる
    return 0;
}