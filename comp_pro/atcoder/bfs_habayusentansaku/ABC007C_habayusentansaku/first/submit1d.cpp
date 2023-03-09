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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void GShow(int R,int C,vector<vector<int>> &G){
    for(int j=0;j<R;j=j+1){
        for(int k=0;k<C;k=k+1){
            debug1(" %d",G[j][k]);
        }
        debug1("\n");
    }
}

int main(void){
    initial();
    int R,C,sy,sx,gy,gx;
    cin >> R >> C;
    cin >> sy >> sx;
    sy=sy-1;
    sx=sx-1;
    cin >> gy >> gx;
    gy=gy-1;
    gx=gx-1;
    vector<vector<int>> G(R,vector<int>(C,0));
    vector<vector<int>> D(R,vector<int>(C,0)); // 訪問済みか否かを確認する
    // 未訪問 0 訪問済み 1 訪問不可 -1
    vector<vector<int>> L(R,vector<int>(C,0)); // 距離を入れる
    for(int j=0;j<R;j=j+1){
        for(int k=0;k<C;k=k+1){
            char t;
            cin >> t;
            G[j][k]=(int)t;
            if(G[j][k]==35){ // '#'
                D[j][k]=-1;// 訪問不可 未訪問はD作成時に入れている
            }
        }
    }
    debug1("-----Gの中身-----\n");
    GShow(R,C,G);
    debug1("-----Dの中身-----\n");
    GShow(R,C,D);
    debug1("-----Lの中身-----\n");
    GShow(R,C,L);
    // 幅優先探索開始
    queue<pair<int,int>> que;
    que.push(make_pair(sy,sx));
    L[sy][sx]=0;
    vector<int> dh = {1,0,-1,0};
    vector<int> dw = {0,1,0,-1};
    while(que.empty()==false){
        pair<int,int> nowpos=que.front();
        if(nowpos.first == gy && nowpos.second == gx){
            debug1("ゴールに着きました->まとめて終了\n");
            break;
        }
        bool is_go=false;
        for(int j=0;j<4;j=j+1){
            int ny,nx;
            ny = nowpos.first+dh[j];
            nx = nowpos.second+dw[j];
            debug(make_pair(ny,nx));
            if(D[ny][nx]==-1){ // 訪問できない
                debug1("[%d][%d]は訪問不可->飛びます\n",ny,nx);
                continue;
            }
            else{
                if(D[ny][nx]==1){ // すでに訪問済み
                    debug1("[%d][%d]は訪問終了->飛びます\n",ny,nx);
                    continue;
                }else
                {
                    L[ny][nx]=L[nowpos.first][nowpos.second]+1;
                    debug1("[%d][%d]を次の訪問先に追加と共に長さ %d 追加\n",ny,nx,L[ny][nx]);
                    is_go=true;
                    que.push(make_pair(ny,nx));
                }
            }
        }
        if(is_go){
            debug1("[%d][%d]からは行くところがありました\n",nowpos.first,nowpos.second);
        }
        else{
            debug1("[%d][%d]からはもう行くところがありません\n",nowpos.first,nowpos.second);
        }
        D[nowpos.first][nowpos.second]=1;
        debug1("[%d][%d] 訪問後の状態1D\n",nowpos.first,nowpos.second);
        GShow(R,C,D);
         debug1("[%d][%d] 訪問後の状態1L\n",nowpos.first,nowpos.second);
        GShow(R,C,L);
        que.pop();
    }
    debug1("----- while 文 終了後 -----\n");
    GShow(R,C,L);
    cout << L[gy][gx] << "\n" << flush;
    return 0;
}

