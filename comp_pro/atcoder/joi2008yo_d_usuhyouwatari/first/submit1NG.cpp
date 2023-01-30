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

// 大域変数
vector<vector<int>> G; // 湖の表
int maxArea=0;

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

void dfs(int y,int x,int nowArea){
    debug("-> 深さ %d : dfs [%d][%d]にて調査\n",nowArea,x,y);
    // 以降debugコマンドの中身には「\t」を先頭に追加
    // 今の位置の氷を割る
    G[x][y] = 0;
    // 左
    if( G[x-1][y] == 1){
        dfs(y,x-1,nowArea+1);
    }
    // 右
    if( G[x+1][y] == 1){
        dfs(y,x+1,nowArea+1);
    }
    // 上
    if ( G[x][y-1] == 1 ){
        dfs(y-1,x,nowArea+1);
    }
    if ( G[x][y+1] == 1){
        dfs(y+1,x,nowArea+1);
    }
    G[x][y] = 1;
    // もう全部0の場合
    if( ( G[x-1][y] || G[x+1][y] || G[x][y+1] || G[x][y-1]) == 0)
    {
        debug("\t(%d,%d)ではもう前後左右には行けません\n",x,y);
        chmax(maxArea,nowArea+1);
    }
}

int main(void){
    initial();
    int mx,ny;
    cin >> mx >> ny;
    G.resize(ny+2,vector<int>(mx+2));
    vector<vector<int>> Gtmp(mx,vector<int>(ny));
    for(int j=0;j<ny;j=j+1){
        for(int k=0;k<mx;k=k+1){
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
    for(int y=0;y<G.size();y=y+1){
        for(int x=0;x<G[0].size();x=x+1){
            if(G[x][y]==1){
                dfs(x,y,0);
            }
        }
    }
    cout << maxArea << "\n" << flush;
    return 0;
}
