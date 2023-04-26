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
const int MAXSIZE = 1010;
vector<vector<char>> G(MAXSIZE,vector<char>(MAXSIZE,'X'));
vector<vector<int>> dist(MAXSIZE,vector<int>(MAXSIZE,yamaMAX_INT));
int H;
int W;
int N;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showG(int MAXH,int MAXW){
    debug("H = %d : W = %d\n",MAXH,MAXW);
    for(int h=0;h<MAXH;h=h+1){
        for(int w=0;w<MAXW;w=w+1){
            debug(" %c",G[h][w]);
        }
        debug("\n");
    }
    debug("\n");
}
void showDist(int H2,int W2){
    debug("H = %d : W = %d\n",H2,W2);
    for(int h=0;h<H2;h=h+1){
        for(int w=0;w<W2;w=w+1){
            if(dist[h][w] == yamaMAX_INT){
                debug("   X");
            }
            else{
                debug(" %2d",dist[h][w]);
                }
        }
        debug("\n");
    }
    debug("\n");
}
int solver(pos &fromP,pos &toP,int H2,int W2){
    int answer=0;
    debug("( %d , %d )->( %d , %d )探索\n",fromP.first,fromP.second,
    toP.first,toP.second);
    int sh = fromP.first;
    int sw = fromP.second;
    int gh = toP.first;
    int gw = toP.second;
    vector<int> dh={1,0,-1,0};
    vector<int> dw={0,1,0,-1};
    queue<pos> P;
    dist[sh][sw]=0;
    P.push(fromP);
    while(P.empty()==false){
        pos npos=P.front();
        P.pop();
        int nposh=npos.first;
        int nposw=npos.second;
        debug("今 (%d,%d)について調査中\n",nposh,nposw);
        if(nposh==gh && nposw== gw){
            answer=dist[nposh][nposw];
            break;
        }
        for(int j=0;j<4;j=j+1){
            int nextposh=nposh+dh[j];
            int nextposw=nposw+dw[j];
            if(dist[nextposh][nextposw]!=yamaMAX_INT){
            debug("dist[%d][%d]=%d\n",nextposh,nextposw,
                dist[nextposh][nextposw]);
                continue;
            }
            else{
                if(G[nextposh][nextposw]=='X'){
                    debug("G[%d][%d]=%c\n",nextposh,nextposw,G[nextposh][nextposw]);
                    continue;
                }
                else{
                pos nextpos = make_pair(nextposh, nextposw);
                P.push(nextpos);
                dist[nextposh][nextposw] = dist[nposh][nposw] + 1;
                }
            }
        }
    }
    showDist(H2+2,W2+2);
    dist.assign(MAXSIZE,vector<int>(MAXSIZE,yamaMAX_INT));
    return answer;
}

int main(void){
    initial();
    int H,W,N;
    cin >> H >> W >> N;
    // 図面の取り込み
    for(int h=1;h<=H;h=h+1){
        for(int w=1;w<=W;w=w+1){
            cin >> G[h][w] ;
        }
    }
    showG(H+2,W+2);
    // 位置の集計
    vector<pos> F(N+1);
    // Sを探す
    for(int h=0;h<H+2;h=h+1){
        for(int w=0;w<W+2;w=w+1){
            if(G[h][w]=='S'){
                F[0]=make_pair(h,w);
                break;
            }
        }
    }
    // 工場の位置の記録
    debug("この図は縦 %d- 横 %d\n",H,W);
    for(int n=1;n<=N;n=n+1){
        char obj='0'+n;
        for(int h=0;h<H+2;h=h+1){
            for(int w=0;w<W+2;w=w+1){
                if(G[h][w] == obj){
                    debug("G[%d][%d]に %c 発見\n",h,w,G[h][w]);
                    F[n]=make_pair(h,w);
                    break;
                }
            }
        }
    }

    debug("FC スタート (%d , %d)\n",F[0].first,F[0].second);
    for(int j=1;j<=N;j=j+1){
        debug("FC 工場 %d (%d , %d)\n",j,F[j].first,F[j].second);
    }
    int result=0;
    for(int n=1;n<=N;n=n+1){
        int eachdist=0;
        // debug("ABCDE F[%d]->F[%d]\n",n-1,n);
        eachdist = solver(F[n-1],F[n],H,W);
        result = result + eachdist;
    }
    cout << result << "\n" << flush;
    return 0;
}

