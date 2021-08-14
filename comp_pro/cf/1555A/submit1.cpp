#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll solve(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll result=0;
    ll person;
    ll needpizza;
    cin >> person;
    if(person < 7){
        result = 15;
        return result;
    }
    if(person & 1){ // もしかしてこの段階で計算してる？ ← 関係なし
        needpizza = (person + 1) ;
    }
    else{// else抜かすとここの計算すべてしてしまう
        needpizza = person ;
    }
    result = ll((needpizza * 5) / 2);
    return result;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll testsize;
    cin >> testsize;
    for(ll j = 0;j < testsize ; j++){
        cout << solve() << "\n";
    }
    return 0;
}
/** 実行結果
--- in
6
12
15 ← ? <- 16だとあってる？
300
1
9999999999999999 <- 10000000とかはどう？
3
--- out
30
37 <- ?
750
2
24999999999999997 <-? 
7

? は計算すると 素直に答えになる
6枚までは単純に6枚のピザ一枚買う15になる
 **/ 
