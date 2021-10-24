#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using ll=long long;
// ★ #define によるマクロは使わなくても上手くいくのか
// ↓のやり方はやはりNG
// 使い方についてはここを参照
// https://cpprefjp.github.io/lang/cpp11/constexpr.html
// template<typename T>
// constexpr FOR(T j,T n) {return for(int (j)=0;(j)<(int)(n);(j)++)}



// やっぱりここであるように#defineが有効な様だ
#define REP(i,n) for(int (j)=0;(j) < (int)(n);++(j))

void initial(void){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    REP(j,10){
        std::cout<< j << "\n";
    }

    return 0;
}

/** 出力結果 
0
1
2
3
4
5
6
7
8
9
**/