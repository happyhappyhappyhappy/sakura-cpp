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
vector<vector<bool>> used(16,vector<bool>(16,false));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int dfs(int x,int y,int a){
    if(H == y) {
        debug("H=%d,y=%d\n",H,y);
        int tf=int(a==0);
        debug("tf=%d\n",tf);
        return a == 0;
    }
    if(W == x){
        return dfs(0,y+1,a);
    }
    if(used[y][x]==true){
        return dfs(x+1,y,a);
    }
    int res=0;
    if( (y+1<H) && (used[y+1][x]==false) && (0 < a)){
        used[y][x]=true;
        used[y+1][x]=true;
        res=res+dfs(x+1,y,a-1);
        used[y+1][x]=false;
        used[y][x]=false;
    }
    if( (x + 1 < W) && (used[y][x+1]==false) && (0<a)){
        used[y][x]=true;
        used[y][x+1]=true;
        res=res+dfs(x+1,y,a-1);
        used[y][x]=false;
        used[y][x+1]=false;
    }
    res=res+dfs(x+1,y,a);
    return res;
}

int main(void){
    initial();
    cin >> H >> W >> A >> B;
    int ans=dfs(0,0,A);
    cout << ans << "\n" << flush;
    return 0;
}
