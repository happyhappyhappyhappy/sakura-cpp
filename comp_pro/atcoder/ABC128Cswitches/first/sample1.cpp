#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
// TODO: とりあえず
// https://atcoder.jp/contests/abc128/submissions/5778021
// をコピーペーストしてどう入力されるか見ておく

int main(void){

    int N,M; // スイッチの数,電球の数
    cin >> N >> M;
    vector<int> S[10]; // Sはint型のvectorになっている
    vector<int> P(10); // 2で割った値がこの値になっていれば光る
    for(int j=0;j<M;j=j+1) // 電球の分をカウント
    {
        for(int k=0;k<N;k=k+1){ 


        }
    }

    return 0;
}