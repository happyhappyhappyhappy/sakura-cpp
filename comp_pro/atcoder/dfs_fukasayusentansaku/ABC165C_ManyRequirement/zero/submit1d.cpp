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

// 大域変数
int N,M,Q; // N=個数,M=最大値,Q=条件数
vector<int> a; // ここから
vector<int> b; // これを引くと
vector<int> c; // これになった
vector<int> d; // その時のポイント

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // 大域変数に値入力
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
}
void showCheck(void){
    debug("N=%3d,M=%3d,Q=%3d\n",N,M,Q);
    for(int j=0;j<Q;j=j+1){
        debug("b[%d]=%3d - a[%d]=%3d ? c[%3d]=%3d -> get d[%3d]=%3d\n",
        j,b[j],j,a[j],j,c[j],j,d[j]);
    }
}
void showA(int C,vector<int> &A){
    if(C==0){
        debug("今Aには何も入っていません\n");
        return;
    }
    debug("ただ今のA↓\n");
    for(int j=0;j<C;j=j+1)
    {
        debug(" %3d",A[j]);
    }
    debug("\n");
    return;
}
int dfs(int C,vector<int> &A){
    showA(C,A);
    if(C == N){
        int score=0;
        for(int j=0;j<Q;j=j+1){
            if(A[b[j]]-A[a[j]]==c[j]){
                score=score+d[j];
            }
        }
        return score;
    }
    int lastNum=-1; // -1は半ばダミー
    if(C == 0){
        lastNum=1;
    }else{
        lastNum=A[C-1];
    }

    int res=0;
    for(int j=lastNum;j<=M;j=j+1){
        int nowres=0;
        A.push_back(j);
        nowres=dfs(C+1,A);
        if(res<nowres){
            debug("L.%3d in C=%3d: %3d < %3d 最大値を %3dと変更しました\n"
            ,__LINE__,C,res,nowres,nowres);
            res=nowres;
        }
        A.pop_back();
    }
    return res;
}
int main(void){
    initial();
    // showCheck();

    vector<int> A;
    int res;
    res=dfs(0,A);
    cout << res << "\n" << flush;
    return 0;
}
