#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#else
#define debug1(...) 42
#define debug2(...) 42
#endif
using namespace std;
using ll=long long;
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}

// 大域変数
vector<vector<int>> G;
int H,W;
int maxTile=0;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void show(vector<vector<int>> PLOT){
    int hsize = (int)PLOT.size();
    int wsize = (int)PLOT[0].size();
    debug2("%d x %d のテーブル出力",hsize,wsize);
    for(int j=0;j<hsize;j=j+1){
        for(int k=0;k<wsize;k=k+1){
            debug1(" %d",PLOT[j][k]);
        }
        debug1("\n");
    }
}

void explorer(vector<vector<int>> &P,int h,int w,int depth){
    debug2("深さ %d :(%d,%d)から探索を開始します",depth,h,w);
    P[h][w] = 0; // (h,w)を割る
    vector<int> dh={1,-1,0,0};
    vector<int> dw={0,0,1,-1};
    int nextExplorer=0;
    for(int j=0;j<4;j=j+1){
        int nexth= h + dh[j];
        int nextw= w + dw[j];
        if(P[nexth][nextw] == 2){
            debug2("(%d,%d)はエリア外のため探索せず",nexth,nextw);
            continue;
        }
        if(P[nexth][nextw] == 0){
            debug2("(%d,%d)は氷が張ってないので探索せず",nexth,nextw);
            continue;
        }
        debug2("(%d,%d)は進めそうだので進行",nexth,nextw);
        nextExplorer=1;
        explorer(P,nexth,nextw,depth+1);
    }
    if(nextExplorer == 0){
        debug2("(%d,%d)から進行できないので最大と照合",h,w);
        chmax(maxTile,depth+1);
    }
    debug2("(%d,%d) を埋め直した後戻ります",h,w);
    P[h][w] = 1;
}

int main(void){
    initial();
    cin >> W >> H;
    // G.resize(H+2);
    // G[0].resize(W+2);
    G.resize(H+2,vector<int>(W+2,2));
    vector<vector<int>> givenG(H,vector<int>(W,0));
    for(int j=0;j<H;j=j+1){
        for(int k=0;k<W;k=k+1){
            cin >> givenG[j][k];
        }
    }
    // for(int j=0;j<H+2;j=j+1){
    //     for(int k=0;k<W+2;k=k+1){
    //         G[j][k]=2;
    //     }
    // }
    // show(givenG);
    // show(G);
    //  転写
    for(int j=0;j<H;j=j+1){
        for(int k=0;k<W;k=k+1){
            G[j+1][k+1] = givenG[j][k];
        }
    }
    show(G);
    for(int j=0;j<H+2;j=j+1){
        for(int k=0;k<W+2;k=k+1){
            if(G[j][k] == 1){
                explorer(G,j,k,0);
            }
        }
    }
    cout << maxTile << "\n" << flush;
    return 0;
}

