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
int H,W,A,B;
vector<vector<int>> used;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showUsed(void){
    // int h=used.size();
    // int w=used[0].size();
    for(int j=0;j<H;j=j+1){
        for(int k=0;k<W;k=k+1){
            debug("%3d",used[j][k]);
        }
        debug("\n");
    }
}
int dfs(int x,int y,int a){
    debug("現在位置(%d,%d) , 長方形の枚数 = %d\n",x,y,a);
    // showUsed();
    if(y == H){
        if(a == 0){
            debug("無事長方形使い切っている 1プラス\n");
            return 1;
        }
        else{
            debug("長方形 %d 枚余ってしまったNG\n",a);
            return 0;
        }
    }
    if(x == W){
        return dfs(0,y+1,a);
    }
    if(used[y][x]==1){
        return dfs(x+1,y,a);
    }
    int pat1=0;
    int pat2=0;
    int pat3=0;
    // 横置き
    if((x+1<W) && (used[y][x+1]==0) && (0<a)){
        used[y][x+1]=1;
        used[y][x]=1;
        pat1=dfs(x+1,y,a-1);
        used[y][x+1]=0;
        used[y][x]=0;
    }
    // 縦置き
    if((y+1<H) && (used[y+1][x]==0) && (0<a)){
        used[y][x]=1;
        used[y+1][x]=1;
        pat2=dfs(x+1,y,a-1);
        used[y][x]=0;
        used[y+1][x]=0;
    }
    // 置かない
    pat3=dfs(x+1,y,a);
    return pat1+pat2+pat3;
}
int main(void){
    initial();
    cin >> H >> W >> A >> B;
    used.assign(H+1,vector<int>(W+1,0));
    int ans=dfs(0,0,A);
    cout << ans << "\n" << flush;
    return 0;
}
