#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
// i++ , ++i の違いサンプル集。Codeforceで問題を扱うときのポイント
// https://qiita.com/suuungwoo/items/e054fdcb5a4805bb226b

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}

int main(void){
    initial();
    int base,after;
    base = 1;
    cout << "++iの場合 :: " ;
    after = ++base;
    cout << after << "\n";
    base = 1;
    cout << "i++の場合 :: ";
    after = base ++;
    cout << after << "\n";
    cout << "Codeforceの問題数について、まず10個問題がある場合\n";
    int testcase = 10;
    while(testcase--){
        int testNo = 10 - testcase; // これは表示用に用意しただけ、実際は問題番号に影響なし
        cout << "ただいま " << testNo << " 番目の処理を行っています\n";
    }
    cout << "無事にループを抜けました\n";
    return 0;
}
/**
実行結果 
++iの場合 :: 2 <- 足した後の値を見ている
i++の場合 :: 1 <- 足す前の値を見ている
Codeforceの問題数について、まず10個問題がある場合
ただいま 1 番目の処理を行っています
ただいま 2 番目の処理を行っています
ただいま 3 番目の処理を行っています
ただいま 4 番目の処理を行っています
ただいま 5 番目の処理を行っています
ただいま 6 番目の処理を行っています
ただいま 7 番目の処理を行っています
ただいま 8 番目の処理を行っています
ただいま 9 番目の処理を行っています
ただいま 10 番目の処理を行っています
無事にループを抜けました
 **/