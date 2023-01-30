#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
// TODO: 自作とサンプルのハイブリッド->実行確認 2023年1月30日

// 大域変数
vector<vector<int>> G; // 湖の表
int maxArea=0; // 最大数
// 上下左右進行表
vector<int> dw[4]={1,-1,0,0};
vector<int> dh[4]={0,0,1,-1};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void gCopy(vector<vector<int>> &fromG,vector<vector<int>> &toG){
    int y = fromG.size();
    int x = fromG[0].size();
    for(int j=0;j<y;j=j+1){
        for(int k=0;k<x;k=k+1){
            toG[j+1][k+1] = fromG[j][k];
        }
    }
}

void dfs(int h,int w,int nowArea){
    debug("-> 深さ %d : dfs [%d][%d]にて調査\n",nowArea,h,w);
    // 以降debugコマンドの中身には「\t」を先頭に追加
    // 今の位置の氷を割る
    G[h][w] = 0;
    // 左

    // if( G[x-1][y] == 1){
    //     dfs(y,x-1,nowArea+1);
    // }
    // // 右
    // if( G[x+1][y] == 1){
    //     dfs(y,x+1,nowArea+1);
    // }
    // // 上
    // if ( G[x][y-1] == 1 ){
    //     dfs(y-1,x,nowArea+1);
    // }
    // if ( G[x][y+1] == 1){
    //     dfs(y+1,x,nowArea+1);
    // }
    bool step_ok=false;
    for(int j=0;j<4;j=j+1){
        int nh = h + dh[j];
        int nw = w + dw[j];
        if(G[nh][nw]==1){
            dfs(nh,nw,nowArea+1);
            step_ok=true;
        }
    }
    if(step_ok==false){
        debug("(%d,%d)から上下左右に進めないので計算します\n",h,w);
        chmax(maxArea,nowArea);
    }
    else{
        debug("(%d,%d)から上下左右に進めます。次行きます\n",h,w)
    }
    // もう元に戻す+引き返す

    G[x][y] = 1;
    nowArea=nowArea-1;
    // もう全部0の場合 -> step_ok 変数で処理に変えました

}

int main(void){
    initial();
    int mw,nh;
    cin >> mw >> nh;
    G.resize(nh+2,vector<int>(mw+2));
    vector<vector<int>> Gtmp(nh,vector<int>(mw));
    for(int j=0;j<nh;j=j+1){
        for(int k=0;k<mw;k=k+1){
            int nowStatus;
            cin >> nowStatus;
            Gtmp[j][k]=nowStatus;
        }
    }
    gCopy(Gtmp,G);
    // for(int j=0;j<G.size();j=j+1){
    //     for(int k=0;k<G[0].size();k=k+1){
    //         debug(" %d",G[j][k]);
    //     }
    //     debug(" \n");
    // }
    for(int h=0;h<G.size();h=h+1){
        for(int w=0;w<G[0].size();w=w+1){
            if(G[h][w]==1){
                dfs(h,w,0);
            }
        }
    }
    cout << maxArea << "\n" << flush;
    return 0;
}
