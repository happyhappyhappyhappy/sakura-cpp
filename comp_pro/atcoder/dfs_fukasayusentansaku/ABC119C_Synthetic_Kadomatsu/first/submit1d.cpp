#include<bits/stdc++.h>
#ifdef LOCAL
// #include"/wrk/sakura-cpp/comp_pro/debug.h"
// #include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include<debug/debug.h>
#include<debug/tdebug.h>
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;

// グローバル変数
int N; // 手持ちの竹の数
int A,B,C; // 完成させる長さ
vector<int> L; // 手持ちの竹の長さ

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showData(void){
    debug("N = %d, A = %d, B = %d, C = %d\n",N,A,B,C);
    for(auto &d:L){
        debug(" %d ",d);
    }
    debug("\n");
}
int dfs(int n,int a,int b,int c){
    if(n == N){
        int minL = min(a,b,c);
        if(minL>0){
            debug("竹そのものは揃っているので[%d,%d,%d]増減魔法で調整\n",a,b,c);
            int sumMP=0;
            vector<int> MP(3,0);
            MP[0] = abs(a,A);
            MP[1] = abs(b,B);
            MP[2] = abs(c,C);
            for(int j=0;j<3;j=j+1){
                sumMP=MP[j];
            }
            debug("単純計算 魔法量 %d\n",sumMP);
            debug("しかし、竹を置くだけは魔法を利用しないので初回合成魔法 30MP は削って返す\n");
            sumMP=sumMP-30;
            debug("完成時(%d,%d,%d)に使う魔法最終値 %d\n",a,b,c,sumMP);
            return sumMP;
        }
        else{
            debug("%d本そろえて  a=%d,b=%d,c=%d\n",n,a,b,c);
            if(a<=0){
                debug("Aを作成出来ません\n");
            }
            if(b<=0){
                debug("Bを作成出来ません\n");
            }
            if(c <= 0){
                debug("Cを作成出来ません\n");
            }
            return pow(10^9);
        }
    }
    int mp0 = dfs(n+1,a,b,c); // n本目の竹はどこにも合成しない
    debug("%d 本目の竹は使わなかったときの最小 %d\n",n,mp0);
    int mpA = dfs(n+1,a+L[n],b,c)+10; // n本目の竹はAに使う
    debug("%d 本目の竹を A に使ったときの最小 %d\n",n,mpA);
    int mpB = dfs(n+1,a,b+L[n],c)+10; // n本目の竹はBに使う
    debug("%d 本目の竹を B に使ったときの最小 %d\n",n,mpB);
    int mpC = dfs(n+1,a,b,c+L[n])+10; // n本目の竹はCに使う
    debug("%d 本目の竹を C に使ったときの最小 %d\n",n,mpC);
    int minmp = min(mp0,mpA,mpB,mpC); // それぞれ使ったときの最小魔法を決める
    return minmp;
}
int solver(void){
    int res=0;
    // showData();
    res = dfs(0,0,0,0);
    return res;
}
int main(void){
    initial();
    cin >> N >> A >> B >> C;
    L.resize(N);
    for(int j=0;j<N;j=j+1){
        cin >> L[j];
    }
    cout << solver() << "\n" << flush;
    return 0;
}
