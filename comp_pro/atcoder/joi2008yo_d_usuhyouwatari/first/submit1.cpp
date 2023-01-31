#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> bool chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

// 大域変数
vector<vector<int>> G; // 湖の表
int maxArea=0; // 最大数
// 上下左右進行表
vector<int> dw={1,-1,0,0};
vector<int> dh={0,0,1,-1};

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
    // debug("<開始> -> 深さ %d : dfs [%d][%d]にて調査\n",nowArea,h,w);
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
    bool step_ok=false; // 次に何かしらの移動を行ったか示す
    for(int j=0;j<4;j=j+1){
        int nh = h + dh[j];
        int nw = w + dw[j];
        if(G[nh][nw]==1){
            dfs(nh,nw,nowArea+1);
            step_ok=true; // 移動を実行した
        }
    }
    if(step_ok==false){
        // debug("(%d,%d)から上下左右に進めないのでこの段階の長さを「%d」と枝刈りします\n",h,w,nowArea+1);
        if(chmax(maxArea,nowArea+1)){
            // debug("\t最長距離を--%d--に更新しました\n",maxArea);
        }
        else
        {
            // debug("\t最長記録は変わりません\n");
        }
    }
    else{
        // debug("(%d,%d)から上下左右に進めます。次に行ってます\n",h,w);
    }
    // もう元に戻す+引き返す

    G[h][w] = 1;
    // debug("<終了> -> 深さ %d : dfs [%d][%d]にて調査\n",nowArea,h,w);

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
    for(int h=0;h<(int)G.size();h=h+1){
        for(int w=0;w<(int)G[0].size();w=w+1){
            if(G[h][w]==1){
                dfs(h,w,0);
            }
        }
    }
    cout << maxArea << "\n" << flush;
    return 0;
}
