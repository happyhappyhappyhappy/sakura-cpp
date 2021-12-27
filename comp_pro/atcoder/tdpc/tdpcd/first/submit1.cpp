#include<bits/stdc++.h>
using namespace std;
using ll=long long;
// #define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

// 大域変数はN回の数におうじて代わるのでここでは宣言できない
// const int N_MAX=100;
// 6^100に合わせようとするとメモリフルになってエラーが出る
// double dp[110][260][165][113];
// 基本の倍数に依るだけとすれば
static int Nmax = 100;
static int X2max = 60;
static int X3max = 38;
static int X5max = 26;
double dp[Nmax+1][X2max+1][X3max+1][X5max+1];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    for(ll ii=0;ii <= Nmax ;ii++){
        for(ll j=0;j<= X2max;j++){
            for(ll k=0;k<= X3max;k++){
                for(ll m=0;m<= X5max;m++){
                    dp[ii][j][k][m]=0.0;
                }
            }
        }
    }
    dp[0][0][0][0]=1.0000;
}
/**
bool prime_fac(ll &x2,ll &x3,ll &x5,&d){
    // 与えられた数にはどれくらい2,3,5の倍数があるか
    // 引数 x2(2の倍数),x3(3の倍数),x5(5の倍数),与えられた数D
    // 出力 bool : true Dの残骸が1である(つまりサイコロの積に含む)
    //          : false 1以外(この値だとどうしてもサイコロの積にならない)
    // それ以外の情報は、引数は参照渡しにする
    // 2の倍数いくつになるか
    while(true){
        if(d % 2)// TODO: 2の累乗数をいくつかにするかからスタート
    }
    return true;
}
*/
int main(void){
    initial();
    ll N,D;
    cin >> N >> D;// N:振る数 D:倍数
    ll X2,X3,X5,surpus_D;
    X2 = 0;
    X3 = 0;
    X5 = 0;
    surpus_D = D;
    bool exist_ed=false;
 //   exist_ed=prime_fac(X2,X3,X5,surpus_D);
 //   if(not_exist_ed){
 //       cout << "サイコロの目ではDの倍数になりません" << "\n" << flush;
 //       cout << 0.0 << "\n" << flush;
 //       return 0;
//    }
//    cout << "動的計画法で求めます" << "\n" << flush;
    return 0;
}
