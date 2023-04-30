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
using pos=pair<int,int>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;
// 大域変数
vector<vector<char>> G;
// vector<vector<int>> dir;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showG(int H,int W){
    for(int h=0;h<H;h=h+1){
        for(int w=0;w<W;w=w+1){
            debug(" %c",G[h][w]);
        }
        debug("\n");
    }
    debug("\n");
}
pos getpos(int H,int W,char p){
    pos ansp=make_pair(-1,-1);
    for(int h=0;h<H;h=h+1){
        for(int w=0;w<W;w=w+1){
            if(G[h][w] == p){
                debug("G[ %d ][ %d ]に %c 発見\n",h,w,p);
                ansp=make_pair(h,w);
            }
        }
    }
    return ansp;
}

void showDir(vector<vector<int>> &dir,int H,int W){
    for(int h=0;h<H;h=h+1){
        for(int w=0;w<W;w=w+1){
            if( dir[h][w] == yamaMAX_INT){
                debug(" .");
            }
            else{
                debug(" %d",dir[h][w]);
            }
        }
        debug("\n");
    }
    debug("\n");
}

int solver(pos F,pos T,int H,int W){
    vector<vector<int>> dir(H,vector<int>(W,yamaMAX_INT));
    debugt(F);
    debugt(T);
    int result=0;
    int sh = F.first;
    int sw = F.second;
    int gh = T.first;
    int gw = T.second;
    vector<int> dh={1,0,-1,0};
    vector<int> dw={0,1,0,-1};
    queue<pos> Q;
    Q.push(F);
    dir[sh][sw]=0;

    while(Q.empty()==false){
        pos n = Q.front();
        Q.pop();
        int nh = n.first;
        int nw = n.second;
        if(nh == gh && nw == gw)
        {
            result = dir[nh][nw];
            break;
        }
        for(int j=0;j<4;j=j+1){
            int nexth = nh+dh[j];
            int nextw = nw+dw[j];
            if(G[nexth][nextw]=='X'){
                continue;
            }
            if(dir[nexth][nextw]!=yamaMAX_INT){
                    continue;
            }
            dir[nexth][nextw]= dir[nh][nw]+1;
            Q.push(make_pair(nexth,nextw));
            }
        }
    showDir(dir,H,W);
    debugt(F);
    debugt(T);
    debug("解答 %d\n",result);
    return result;
}
int main(void){
    initial();
    int H,W,N;
    cin >> H >> W >> N;
    int GH=H+2; // 地図の高さ
    int GW=W+2; // 地図の幅
    G.assign(GH,vector<char>(GW,'X'));
    for(int h=1;h<=H;h=h+1){
        for(int w=1;w<=W;w=w+1){
            cin >> G[h][w];
        }
    }
    // showG(GH,GW);
    vector<pos> F(N+1,make_pair(-1,-1));
    F[0] = getpos(GH,GW,'S');
    debug("スタート位置 ( %d , %d )\n",F[0].first,F[0].second);
    // 拡張
    for(int n=1;n<=N;n=n+1){
        char obj = n + '0';
        F[n]=getpos(GH,GW,obj);
        debug("%d 番目 ( %d , %d )\n",n,F[n].first,F[n].second);
    }
    // int res=0;
    for(int j=0;j<N;j=j+1){
        debugt(F[j]);
        debugt(F[j+1]);
    }
    int answer=0;
    for(int j=1;j<=N;j=j+1){
        answer = solver(F[j-1],F[j],GH,GW)+answer;
    }
    cout << answer << "\n" << flush;
    return 0;
}

