#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
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
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
// グローバル変数
int N; // 増加整数順列の個数
int M; // 増加整数順列の最大値
int Q; // 問い合わせの数
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    for(int j=0;j<Q;j++){
        cin >> a[j] >> b[j] >> c[j] >> d[j];
        a[j]=a[j]-1; // 配列を1-index -> 0-index
        b[j]=b[j]-1; // 同上
    }
}
void showQ(void){
    for(int j=0;j<Q;j=j+1){
        debug("Q.%d -> b[%d] - a[%d] = c[%d]  point.%d\n",
        j+1,b[j],a[j],c[j],d[j]);
    }
}
int score(vector<int> &A){ // 配列Aの個数はNと判明している
    int total=0;
    for(int j=0;j<Q;j=j+1){
        if(A[b[j]]-A[a[j]]==c[j]){
            total=total+d[j];
        }
    }
    return total;
}
int dfs(int n,vector<int> &A){
    debug("-----今の %d 個の数列-----\n",n);
    for(auto &e:A){
        debug(" %d ",e);
    }
    debug("\n");
    int res=0;
    if(n == N){
        debug("最大値になったので最終計算します\n");
        res=score(A);
        debug("この時の値は %d です\n",res);
        return res;
    }
    else{
        int lastnum=-1; // -1はダミー初期化
        if(n == 0){
            lastnum = 1;
        }else{
            lastnum = A[n-1];
        }
        for(int j=lastnum;j<=M;j=j+1){
            A.push_back(j);
            int nowres=-1;
            nowres=dfs(n+1,A);
            chmax(res,nowres);
            A.pop_back();
        }
        return res;
    }
}
int main(void){
    initial();
    showQ();
    vector<int> A;
    cout << dfs(0,A) << "\n" << flush;
    return 0;
}
