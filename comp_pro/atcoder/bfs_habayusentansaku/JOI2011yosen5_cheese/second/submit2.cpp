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
vector<vector<char>> G(MAXSIZE,vector<char>(MAXSIZE,'#'));
vector<vector<int>> dist(MAXSIZE,vector<int>(MAXSIZE,yamaMAX_INT));
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showG(int MAXH,int MAXW){
    for(int h=0;h<MAXH;h=h+1){
        for(int w=0;w<MAXW;w=w+1){
            debug(" %c",G[h][w]);
        }
        debug("\n");
    }
    debug("\n");
}

int solver(pos &fromP,pos &toP){
    debug("( %d , %d )->( %d , %d )探索\n",fromP.first,fromP.second,
    toP.first,toP.second);


    // メモ dist図の掃除
    return 1;
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
    for(int n=1;n<=N;n=n+1){
        char obj='0'+n;
        for(int w=0;w<W+2;w=w+1){
            for(int h=0;h<H+2;h=h+1){
                if(G[w][h] == obj){
                    F[n]=make_pair(w,h);
                    break;
                }
            }
        }
    }
    // 念の為に出力
    debug("スタート (%d , %d)\n",F[0].first,F[0].second);
    for(int j=1;j<=N;j=j+1){
        debug("工場 %d (%d , %d)\n",j,F[j].first,F[j].second);
    }
    // 一応 S->1までを調べる
    int result=0;
    for(int n=1;n<=N;n=n+1){
        int eachdist=0;
        eachdist = solver(F[n-1],F[n]);
        result = result + eachdist;
    }
    cout << result << "\n" << flush;
    return 0;
}

