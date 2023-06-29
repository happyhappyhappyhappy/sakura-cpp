// TODO: 問題内容のローカル変数をすべてグローバルに変更
// 2023-06-29 19:33:44
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
using dfs=pair<int,vector<int>>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
// 大域変数 当初全部ローカルにしてましたがさすがにコーディングの無駄
// が多すぎたためこちらに設定します。2023-06-29 19:31:51

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showConfig(int N,int M,int Q,
vector<int> &a,vector<int> &b,vector<int> &c,vector<int> &d){
    debug("数列Aの長さ:%d\n",N);
    debug("数列の取り得る値の最大:%d\n",M);
    debug("質問数:%d\n",Q);
    debug("以下 質問内容\n これから,これを引いて,これなら,得点\n");
    for(int j=0;j<Q;j=j+1){
        debug("要素%d - 要素%d  = %d -> %d\n",b[j],a[j],c[j],d[j]);
    }
    return ;
}
int getScore(int N,vector<int> &X){
    int res=0;


    return res;
}
int solver(vector<int> &A,int N,int M,int Q,
vector<int> &a,vector<int> &b,vector<int> &c,vector<int> &d){
    int res=0;
    showConfig(N,M,Q,a,b,c,d);
    stack<dfs> S;
    S.push(make_pair(0,A));
    while(S.empty()==false){
        dfs D = S.top();
        int leng=D.first;
        vector<int> NowA=D.second;
        if(leng==N){
            debug("完成したのでスコアを計算します\n")
            debug("尚、現在の数列は ")
            for(int j=0;j<N;j=j+1){
                debug(" %4d",NowA[j]);
            }
            debug("\n");
            int score=getScore(NowA,N,a,b,c,d);
            chmax(res,score);
        }

        }
    }

    return res;
}
int main(void){
    initial();
    int res;
    int N,M,Q; // N:数列Aの長さ,M:数列Aが取り得る最大,Q:質問数
    cin >> N >> M >> Q;
    vector<int> a(Q),b(Q); // 差を求めたい数列Aの位置
    // ちなみに「1-index」から「0-index」へ修正する
    vector<int> c(Q); // ↑で求めた差
    vector<int> d(Q); // 一致していたときの点数
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    for(int j=0;j<Q;j=j+1){
        cin >> a[j] >> b[j] >> c[j] >> d[j];
        a[j]=a[j]-1;
        b[j]=b[j]-1;
    }
    vector<int> A;
    res = solver(A,N,M,Q,a,b,c,d);
    cout << res << "\n";
    return 0;
}
