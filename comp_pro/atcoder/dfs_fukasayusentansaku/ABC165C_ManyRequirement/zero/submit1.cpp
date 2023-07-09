#include<bits/stdc++.h>
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
int dfs(int C,vector<int> &A){
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
        chmax(res,nowres);
        A.pop_back();
    }
    return res;
}
int main(void){
    initial();
    vector<int> A;
    int res;
    res=dfs(0,A);
    cout << res << "\n" << flush;
    return 0;
}
