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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfs(vector<vector<int>> &G,
int qno, // これは後になったらいらない
int start_pos,
int addCount,vector<int> &ans){
    int gh = G.size();
    int gw = G[0].size();
    for(int j=0;j<gh;j=j+1){
        debug(" %d -> %d: ",qno,j);
        for(int k=0;k<gw;k=k+1){
            debug(" %d",G[j][k]);
        }
        debug("\n");
    }
}

void solver(vector<vector<int>> &G,vector<vector<int>> &Q,
vector<int> &ans){
    for(int j=0;j<Q.size();j=j+1)
    {
        dfs(G,j,Q[j][0],Q[j][1],ans);
    }
}

int main(void){
    initial();
    // データの取得
    int N,Q;
    cin >> N >> Q;
    // 根の関係
    vector<vector<int>> G(N+1,vector<int>(N+1,0));
    for(int j=0;j<N-1;j=j+1){
        int from,to;
        cin >> from >> to;
        G[from][to] = 1;
    }
    // 値にどれだけ追加するか
    vector<vector<int>> addNum(Q,vector<int>(2,0));
    for(int j=0;j<Q;j=j+1){
        cin >> addNum[j][0] >> addNum[j][1];
    }
    // 回答
    vector<int> ans(N+1,0);
    solver(G,addNum,ans);
    for(int j=0;j<N+1;j=j+1){
        cout << " " << ans[j];
    }
    cout << "\n" << flush;
    return 0;
}

