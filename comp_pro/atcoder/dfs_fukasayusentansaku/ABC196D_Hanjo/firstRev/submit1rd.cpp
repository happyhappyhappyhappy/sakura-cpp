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
// グローバル変数
int H=0; // 縦
int W=0; // 横
int A=0; // 1x2の畳
int B=0; // 1x1の畳
vector<vector<int>> R; // 部屋の見取り図
int res=0; // 回答

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> H >> W >> A >> B;
    R.resize(H+1,vector<int>(W+1,2));// 右端、下端を一旦境界線で再定義
    for(int h=0;h<H;h=h+1){// 基本:何もない半畳を0,1x2の畳を置いた半畳を1とする
        for(int w=0;w<W;w=w+1){
            R[h][w]=0;
        }
    }
}
void dfs(int h,int w,int a){ // 今いる縦軸 h,横軸 w,残枚数 a
    if(h == H){// 全探索終了
        if(a == 0){// 残り無し
            res = res+1;
            return;
        }
        else{ // 残りがある->正しくない設置方法
            return;
        }
    }
    if(R[h][w]==2){ // 右端についた
        dfs(h+1,0,a);
        return;
    }
    if(R[h][w]==1){// すでに使用している(上の行で縦置きした場合に多い)
        dfs(h,w+1,a);
        return;
    }
    // それ以外
    // 横に置きたい場合
    if((a != 0) && (w+1 < W) && (R[h][w+1]==0)){
        R[h][w]=1;
        R[h][w+1]=1;
        dfs(h,w+1,a-1);
        // 次工程のため後片付け
        R[h][w]=0;
        R[h][w+1]=0;
    }
    if((0<a) && (h+1 < H ) && (R[h+1][w]==0)){
        // 縦置きをしたい
        R[h][w]=1;
        R[h+1][w]=1;
        dfs(h,w+1,a-1);
        R[h][w]=0;
        R[h+1][w]=0;
    }
    // 何も置かない
    dfs(h,w+1,a);
    return;
}
int main(void){
    initial();
    dfs(0,0,A);
    cout << res << "\n" << flush;
    return 0;
}
