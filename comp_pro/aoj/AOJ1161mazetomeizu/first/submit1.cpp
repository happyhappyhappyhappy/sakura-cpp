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
using POS=pair<int,int>;
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
// 上下左右12時から右回り90度
vector<int> dh={1,0,-1,0};
vector<int> dw={0,1,0,-1};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
// 高さ,幅
int H,W;

bool canGo1(int posh,int posw,int dh2,int dw2){
    // 枠外に出てしまうケース
    int nexth = posh + dh2;
    int nextw = posw + dw2;
    if(nexth < 0 && H<= nexth){
        return false;
    }
    if(nextw < 0 && W <= nextw){
        return false;
    }
    debug("(%d,%d)から進行(%d,%d)で枠内にはできます\n",posh,posw,dh2,dw2);
    return true;
}

bool canGo2(int posh,int posw,int dh2,int dw2){
// 行きたいのだが行けない
    // 右に行きたい
    if(dw2 == 1 && dh2 == 0 && wall_vert[posh][posw]==1 ){
        return false;
    }
    // 下に行きたい
    if(dw2 == 0 && dh2 == 1 && wall_hori[posh][posw]==1){
        return false;
    }
    // 左に行きたい
    if(dw2 == -1 && dh2 == 0 && wall_veri[posh][posw-1]==1){
        return false;
    }
    // 上に行きたい
    if(dw2 == 0 && dh2 == -1 && wall_hori[posh-1][posw]==1){
        return false;
    }
    debug("(%d,%d)から進行(%d,%d)で行けます\n",posh,posw,dh2,dw2);
    return true;
}

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
                // debug("jが %d まで行きました。抜けます。\n",j);
                continue;
            }
            for(int k=0;k<W;k=k+1){
                cin >> wall_hori[j][k];
            }
        }
        queue<POS> Q;
        POS p = make_pair(0,0);
        Q.push(p);
        dist[p.first][p.second]=0;
        while(Q.empty()==false){
            POS np = Q.front();Q.pop();
            int ph = np.first;
            int pw = np.second;
            for(int j=0;j<4;j=j+1){
                if(canGo1(ph,pw,dh[j],dw[j])==false){
                    continue;
                }
                if(canGo2(ph,pw,dh[j],dw[j])==false){
                    continue;
                }
                else{
                    // 行けると分かった
                    int nh = ph+dh[j];
                    int nw = pw+dw[j];
                    dist[nh][nw]=dist[ph][pw]+1;
                    npos=make_pair(nh,nw);
                    Q.push(npos);
                }
                }
            }
        }
        // debug("\t垂直の壁の情報\n");
        // for(int j=0;j<H;j=j+1){
        // // for(int j=0;j<11;j=j+1){
        //     for(int k=0;k<W-1;k=k+1){
        // //    for(int k=0;k<11;k=k+1){
        //         int d = wall_vert[j][k];
        //         if(d == yamaMAX_INT){
        //             debug(" *");
        //         }
        //         else{
        //             debug("%2d",d);
        //         }
        //     }
        //     debug("\n");
        // }
        // debug("\n\n");
        // debug("\t水平の壁の情報\n");
        // for(int j=0;j<H-1;j=j+1){
        // // for(int j=0;j<11;j=j+1){
        //     for(int k=0;k<W;k=k+1){
        // //    for(int k=0;k<11;k=k+1){
        //         int d = wall_hori[j][k];
        //         if(d == yamaMAX_INT){
        //             debug(" *");
        //         }
        //         else{
        //             debug("%2d",d);
        //         }
        //     }
        //     debug("\n");
        // }
    }
    return 0;
}
