#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}

bool prime_fac(){
    // 与えられた数にはどれくらい2,3,5の倍数があるか
    // 引数 x2(2の倍数),x3(3の倍数),x5(5の倍数),与えられた数D
    // 出力 bool : true Dの残骸が1である(つまりサイコロの積に含む)
    //          : false 1以外(この値だとどうしてもサイコロの積にならない)
    // それ以外の情報は、引数は参照渡しにする
}

int main(void){
    initial();
    int N;
    ll D;
    cin >> N >> D;
    

    return 0;
}
