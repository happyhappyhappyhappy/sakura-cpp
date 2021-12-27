#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
// 配列に動的に要素数を入れて大丈夫か検証 2021/12/27

bool dynaX(int &x){
    cin >> x;
    return false;
}

int main(void){
    int X2;
    bool check;
    if(dynaX(X2)){
        cout << "処理終了\n" << flush;
    }
    int dp[X2];
    for(int ii=0; ii <= X2;ii++){
        dp[ii]=ii;
    }
    for(int ii=0; ii <= X2;ii++){
        cout << dp[ii] << "\n" << flush;
    }
    return 0;
}

// 結果:大丈夫だった
// [kaede@cppkaede sample]$ ./a.out                                   [2021/12/27| 4:06午後]
// 5
// 0
// 1
// 2
// 3
// 4
// 5