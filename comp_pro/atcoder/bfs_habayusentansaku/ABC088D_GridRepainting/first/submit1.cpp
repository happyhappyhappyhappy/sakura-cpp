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

vector<vector<char>> G(60,vector<char>(60,'#'));
vector<vector<int>> DIR(60,vector<int>(60,yamaMAX_INT));
// H,Wはローカル変数で扱う

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showDIR(int H,int W,int line){
    debug("------ %d 回目の term ------\n",line);
    for(int h=0;h<H;h=h+1){
        for(int w=0;w<W;w=w+1){
            if(DIR[h][w]==yamaMAX_INT){
                debug("  .");
            }
            else{
                debug("%3d",DIR[h][w]);
            }
        }
        debug("\n");
    }
    debug("\n");
}
void showG(int H,int W){
    for(int h=0;h<H;h=h+1){
        for(int w=0;w<W;w=w+1){
            debug(" %c",G[h][w]);
        }
        debug("\n");
    }
    debug("Gの出力終了\n");
}
int solver(int H,int W){
    int res=yamaMAX_INT;
    queue<pos> Q;
    pos firstpos=make_pair(1,1);
    vector<int> dh={1,0,-1,0};
    vector<int> dw={0,1,0,-1};
    Q.push(firstpos);
    DIR[1][1]=1; // スタート地点が1枚目
    int line=0;
    while(Q.empty()==false){
        pos npos=Q.front();
        line=line+1;
        Q.pop();
        int nposh=npos.first;
        int nposw=npos.second;
        if((nposh==H) && (nposw==W)){
            res=DIR[H][W];
            break;
        }
        for(int j=0;j<4;j=j+1){
            int nextposh=nposh+dh[j];
            int nextposw=nposw+dw[j];
            if(G[nextposh][nextposw]=='#'){
                continue;
            }
            if(DIR[nextposh][nextposw]!=yamaMAX_INT){
                continue;
            }
            DIR[nextposh][nextposw]=DIR[nposh][nposw]+1;
            Q.push(make_pair(nextposh,nextposw));
        }
        showDIR(H+2,W+2,line);
    }
    if(res == yamaMAX_INT){
        return -1;
    }
    else{
        return res;
    }

}
int main(void){
    initial();
    int H=0;
    int W=0;
    int res=0;
    cin >> H >> W;
    for(int h=1;h<=H;h=h+1){
        for(int w=1;w<=W;w=w+1){
            cin >> G[h][w];
        }
    }
    showG(H+2,W+2);
    res=solver(H,W);// 最短経路は求まった
    if(res == -1){
        cout << res << "\n" << flush;
        return 0;
    }
    // 黒のマスを求める
    int blackf=0;
    for(int h=1;h<=H;h=h+1){
        for(int w=1;w<=W;w=w+1){
            if(G[h][w]=='#'){
                blackf=blackf+1;
            }
        }
    }
    // マスの個数を求める
    int grids=H*W;
    int f_res=grids-blackf-res;
    cout << f_res << "\n" << flush;
    return 0;
}

