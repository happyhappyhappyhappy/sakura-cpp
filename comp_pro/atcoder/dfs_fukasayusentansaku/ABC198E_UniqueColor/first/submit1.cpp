#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
// グローバル変数
int N; // 頂点の個数
vector<int> C; // 各点の色番号
vector<vector<int>> G; // 木の辺
vector<int> DC; // 今までこの色は何回通ったか
vector<int> R; // もうすでに一度はたどった場所か
vector<int> ANS; // 条件を満たすか 1...true,0...false

int maxColor(vector<int> &c,int n){
    int res=-1;
    for(int j=0;j<=n;j=j+1){
        if(res <= c[j]){
            res = c[j];
        }
    }
    return res;
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // グローバル配列の初期化
    cin >> N;
    C.assign(N+1,0);
    for(int j=1;j<=N;j=j+1){
        cin >> C[j];
    }
    G.resize(N+1);
    for(int j=1;j<N;j=j+1){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int AM=maxColor(C,N);
    DC.assign(AM+1,0);
    R.assign(N+1,0);
    ANS.assign(N+1,1);
    ANS[0]=0;
}

void dfs(int t){
    int color_no=C[t];
    int color_cnt=DC[color_no];
    if(color_cnt != 0){
        ANS[t]=0; // もうすでに色を使っていたら
    }
    DC[color_no]=DC[color_no]+1;
    R[t]=1;
    // 次の頂点へ
    for(int j=0;j<int(G[t].size());j=j+1){
        int next_t=G[t][j];
        if(R[next_t]==0){
            dfs(next_t);
        }
    }
    DC[color_no]=DC[color_no]-1;
}
int main(void){
    initial();
    dfs(1); // まずは提案通り最初の頂点だけ流す
    for(int j=0;j<N+1;j=j+1){
        if(ANS[j]==1){
            cout << j << "\n" << flush;
        }
    }
    return 0;
}
