#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

// 目標
// 文字列をひっくり返すのにstd::reverseが使えるか

int main(void){
    string baseStr="takeyabuyaketa";
    reverse(baseStr.begin(),baseStr.end());
    cout << baseStr << "\n";
    return 0;
}