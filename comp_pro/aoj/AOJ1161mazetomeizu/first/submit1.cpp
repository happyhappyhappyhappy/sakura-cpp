#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/t_debug.h"
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
const ll yamaMAX_LL = 1LL << 58;

// 大域変数
// 垂直方向の壁 W-1個
vector<vector<int>> wall_vert(40,vector<int>(40,yamaMAX_INT));
// 水平方向の壁 H個
vector<vector<int>> wall_hori(40,vector<int>(40,yamaMAX_INT));
// 距離
vector<vector<int>> dist(40,vector<int>(40,yamaMAX_INT));
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
// 高さ,幅
int H,W;

int main(void){
    initial();
    while(true){
        cin >> W >> H;
        if(H == 0 && W == 0){
            break;
        }
        for(int j=0;j<H;j=j+1){
            for(int k=0;k<W-1;k=k+1){
                cin >> wall_vert[j][k];
            }
            if(j == H-1){
                debug("jが %d まで行きました。抜けます。\n",j);
                continue;
            }
            for(int k=0;k<W;k=k+1){
                cin >> wall_hori[j][k];
            }
        }
        debug("\t垂直の壁の情報\n");
        for(int j=0;j<H;j=j+1){
            for(int k=0;k<W-1;k=k+1){
                int d = wall_vert[j][k];
                if(d == yamaMAX_INT){
                    debug(" *");
                }
                else{
                    debug("%2d",d);
                }
            }
            debug("\n");
        }
        debug("\n\n");
        debug("\t水平の壁の情報\n");
        for(int j=0;j<H-1;j=j+1){
            for(int k=0;k<W;k=k+1){
                int d = wall_hori[j][k];
                if(d == yamaMAX_INT){
                    debug(" *");
                }
                else{
                    debug("%2d",d);
                }
            }
            debug("\n");
        }
    }
    return 0;
}
