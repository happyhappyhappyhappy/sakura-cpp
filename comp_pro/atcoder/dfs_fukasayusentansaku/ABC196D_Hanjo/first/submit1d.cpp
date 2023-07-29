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
int H,W,A,B; // H 高さ W 幅 A 1x2(2x1)の畳 B 1x1の畳
// used 利用状態 0 何も置いてない 1 畳を置いている -1 境目(何も置けない・チェック用)
// main文で 高さ H+1,幅 W+1に、-1として設置し後で利用可能な所に0を設定
vector<vector<int>> used;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int solver(int h,int w,int a){
    debug("ただいま[%d][%d]  残り枚数 %3d です\n",h,w,a);
    // 最終処理
    if(h == H){
        if(a==0){
            debug("残り無し->問題無く敷き詰めた\n");
            return 1;
        }
        else{
            debug("問題あり:%3d 枚残った\n",a);
            return 0;
        }
    }
    // 右端に到着した次の行に移る
    if(w == W){
        debug("[%d][%d]右端到着、 [%d][%d]に移動\n",h,w,h+1,0);
        return solver(h+1,0,a);
    }
    // 利用中だった→右の位置に移動
    if(used[h][w]==1){
        debug("[%d][%d]利用中、[%d][%d]に移動\n",h,w,h,w+1);
        return solver(h,w+1,a);
    }
    int resTotal=0;
    int res1=0;
    int res2=0;
    int res3=0;
    // 横に置く場合
    if((0<a)&&(w+1<W)&&(used[h][w+1]==0)){
        used[h][w]=1;
        used[h][w+1]=1;
        res1=solver(h,w+1,a-1);
        // 終わったら元に図を戻す
        debug(" [%d][%d] と [%d][%d] に長方形の畳を横で敷きます その結果 = %d\n",h,w,h,w+1,res1);
        used[h][w]=0;
        used[h][w+1]=0;
    }
    // 縦に置く場合
    if((0<a)&&(h+1<H)&&(used[h+1][w]==0)){
        used[h][w]=1;
        used[h+1][w]=1;
        res2=solver(h,w+1,a-1);
        debug(" [%d][%d] と [%d][%d] に長方形の畳を縦で敷きます-> その結果 = %d\n",h,w,h+1,w,res2);
        used[h][w]=0;
        used[h+1][w]=0;
    }
    // 何も置かない場合
    res3 = solver(h,w+1,a);
    debug(" [%d][%d]には長方形の畳を置かなかった->得られた数 = %d\n",h,w,res3);
    resTotal = res1+res2+res3;
    return resTotal;
}
int main(void){
    initial();
    cin >> H >> W >> A >> B;
    used.resize(H+1,vector<int>(W+1,-1));
    for(int j=0;j<H;j=j+1){
        for(int k=0;k<W;k=k+1){
            used[j][k]=0;
        }
    }
    cout << solver(0,0,A) << "\n" << flush;
    return 0;
}
