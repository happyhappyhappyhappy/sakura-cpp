#include<bits/stdc++.h>
using namespace std;
using ll=long long;
// #define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

// 大域変数
const int N_MAX=100;
// 6^100に合わせようとするとメモリフルになってエラーが出る
// double dp[110][260][165][113];

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
    return true;
}

int main(void){
    initial();
    ll N,D;
    cin >> N >> D;// N:振る数 D:倍数
    ll x2,x3,x5,surpus_D;
    x2 = 0;
    x3 = 0;
    x5 = 0;
    surpus_D = D;
    bool not_exist_ed=true;
    // exist_ed=prime_fac(x2,x3,x5,surpus_D);
    if(not_exist_ed){
        cout << "サイコロの目ではDの倍数になりません" << "\n" << flush;
        return 0;
    }
    cout << "動的計画法で求めます" << "\n" << flush;
    return 0;
}
