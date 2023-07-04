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
int N,M,Q; // N:数列Aの長さ,M:数列Aが取り得る最大,Q:質問数
vector<int> a(Q),b(Q); // 差を求めたい数列Aの位置
// ちなみに「1-index」から「0-index」へ修正する
vector<int> c(Q); // ↑で求めた差
vector<int> d(Q); // 一致していたときの点数


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showConfig(void){
    debug("数列Aの長さ:%d\n",N);
    debug("数列の取り得る値の最大:%d\n",M);
    debug("質問数:%d\n",Q);
    debug("以下 質問内容\n これから,これを引いて,これなら,得点\n");
    for(int j=0;j<Q;j=j+1){
        debug("要素%d - 要素%d  = %d -> %d\n",b[j],a[j],c[j],d[j]);
    }
    return ;
}
void showA(int L,vector<int> &X){
    debug("---ただ今の中身---\n");
    if(L == 0){
        debug("ありません");
    }else{
        for(int j=0;j<L;j=j+1){
            debug(" %3d",X[j]);
        }
    }
    debug("\n");
    return;
}
int getScore(vector<int> &X){
    int res=0;
    for(int j=0;j<Q;j=j+1){
        int diff = X[b[j]]-X[a[j]];
        if(diff == c[j]){
            res=res+d[j];
        }
    }
    return res;
}
int solver(void){ // もしかしたらAは要らないかも
    int res=0;
    vector<int> A;
    // showConfig();
    stack<dfs> S;
    S.push(make_pair(0,A));
    while(S.empty()==false){
        dfs n_dfs=S.top();
        S.pop();
        int leng=n_dfs.first;
        vector<int> n_A=n_dfs.second;
        showA(leng,n_A);
        if(leng==N){
            int score=0;
            score = getScore(n_A);
            chmax(res,score);
        }else{
            int start_num;
            if(leng==0){
                start_num=1;
            }else{
                start_num=n_A[leng];
            }
            // ここで徐々に数をN個まで増やしたいがダメだったので
            // stack殺法はペンディングします 2023-06-30 16:49:47
            // LIST構造のコピーで無ければダメなのかね
            // ↑対処した 2023-07-04 19:40:00
            // なんだかんだ言って新変数領域さかないとダメ
            for(int j=start_num;j<M;j=j+1){
                n_A.push_back(j);
                S.push(make_pair(leng+1,n_A));
                n_A.pop_back();
            }
        }
    }
    return res;
}
int main(void){
    initial();
    int res;
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    for(int j=0;j<Q;j=j+1){
        cin >> a[j] >> b[j] >> c[j] >> d[j];
        a[j]=a[j]-1;
        b[j]=b[j]-1;
    }
    res = solver(); // もしかしたらA要らないかも
    cout << res << "\n";
    return 0;
}
