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
// ↓static としても変数として配列宣言は出来ない
// 余地を10にしてください　2021/12/29
double dp[100+1][60+1][38+1][26+1];

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    for(int ii=0;ii<=Nmax;ii++){
        for(int j=0;j<=X2max;j++){
            for(int k=0;k<=X3max;k++){
                for(int m=0;m<=X5max;m++){
                    dp[ii][j][k][m]=0.0;
                }
            }
        }
    }
    dp[0][0][0][0]=1.0;
}

bool prime_fac(int &x2,int &x3,int &x5,ll &d){
    // 2の倍数いくつになるか
    while(true){
        if(d % 2LL != 0){
            break;
        }
        x2 = x2+1;
        d = d / 2LL;
    }
    // 3の倍数いくつになるか
    while(true){
        if(d % 3LL != 0){
            break;
        }
        x3 = x3 + 1;
        d = d / 3LL;
    }
    while(true){
        if(d % 5LL != 0){
            break;
        }
        x5 = x5 + 1;
        d = d / 5LL;
    }
    if(d != 1){ // 2,3,5で割り切れなかった分
        return false;
    }
    return true;
}

int main(void){
    initial();
    ll N,D;
    cin >> N >> D;// N:振る数 D:倍数
    int X2,X3,X5;
    ll surpus_D;
    bool can_xi;
    X2 = 0;
    X3 = 0;
    X5 = 0;
    surpus_D = D;
    can_xi=prime_fac(X2,X3,X5,surpus_D);
    cout << "D = " << D << " :2^ " << X2 << ": 3^ " << X3 << ": 5^ " << X5
    << ": D残骸 " << surpus_D << "\n" << flush; 
    /**
    if(exist_ed){
        cout << "サイコロの目ではDの倍数になりません" << "\n" << flush;
        cout << 0.0 << "\n" << flush;
        return 0;
    }
    cout << "動的計画法で求めます" << "\n" << flush;
    **/
    return 0;
}
