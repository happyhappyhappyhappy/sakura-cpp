#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug1(...) 42
#define debug2(...) 42
#define debug(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
const int YS_MAX_INT=1<<29;

int H,W,sx,sy,gx,gy;
char c[1009][1009];
int dist[1009][1009];
queue<pair<int,int>> Q;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,1};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    cin >> H >> W >> sx >> sy >> gx >> gy;
    debug(make_pair(gx,gy));
    for(int j=1;j<= H;j=j+1){
        for(int k=1;k<= W;k=k+1){
            cin >> c[j][k];
        }
    }
    for(int j=1;j<=H;j=j+1){
        for(int k=1;k<=W;k=k+1){
            dist[j][k] = YS_MAX_INT;
        }
    }
    for(int j=1;j<=10;j=j+1){
        for(int k=1;k<=10;k=k+1){
            debug1("%c",c[j][k]);
        }
        debug1("\n");
    }
    Q.push(make_pair(sx,sy));
    dist[sx][sy]=0;
    while(!Q.empty()){
        int px = Q.front().first;
        int py = Q.front().second;
        Q.pop();
        for(int j=0;j<4;j=j+1){
            int qx = px+dx[j];
            int qy = py+dy[j];
            char nowpos=c[qx][qy];
            if(nowpos != '.'){
                debug1("( %d , %d )は %c の為飛ばします\n",qx,qy,nowpos);
                continue;
            }
            if(dist[qx][qy]!=(YS_MAX_INT)){
                // 通過済み。しかもここでは遅れている。
                debug1("( %d , %d )は 通過済み 距離 %d のため飛ばします\n",qx,qy,dist[qx][qy]);
                continue;
            }
            debug1("( %d , %d )へ続けます\n",qx,qy);
            // 上で最初に設定した値で無ければこれは行けると見て移動
            dist[qx][qy]=dist[px][py]+1;
            Q.push(make_pair(qx,qy));
        }
    }
    cout << dist[gx][gy] << "\n" << flush;
    return 0;
}
