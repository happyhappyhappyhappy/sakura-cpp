#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/touristdebug.h"
#define GS GShow((int)G[0].size(),(int)G.size(),G)
#else
#define GS 42
#define debug1(...) 42
#define debug2(...) 42
#define debug(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
int M,N;
int maxtile=0;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void GShow(int M,int N,vector<vector<int>> &G){
    for(int j=0;j<N;j=j+1){
        for(int k=0;k<M;k=k+1){
            debug1(" %d",G[j][k]);
        }
        debug1("\n");
    }
}

void dfs(vector<vector<int>> &G,int h,int w,int depth){
    debug1("(%d,%d) 深さ %d の探索開始\n",h,w,depth);
    GS;
    // まず今の所を割る
    debug1("(%d,%d) 深さ%d を割ります\n",h,w,depth);
    G[h][w]=0;
    GS;
    // 右へ→左へ→上へ→下へ
    vector<int> dw={1,-1,0,0};
    vector<int> dh={0,0,1,-1};
    // 詰んだか否か確認するフラグ
    bool nowFine=true;
    // もとの位置を戻す
    for(int j=0;j<(int)dw.size();j=j+1){
        int nextH = h+dh[j];
        int nextW = w+dw[j];
        int nextInfo=G[nextH][nextW];
        if(nextInfo != 1){
            debug1("(%d,%d)は%dのため渡れない\n",nextW,nextH,nextInfo);
            continue;
        }
        else{
            debug1("(%d,%d)は渡れる→次の再帰へ\n",nextW,nextH);
            nowFine=false;
            dfs(G,nextH,nextW,depth+1);
        }
    }
    if(nowFine==true){
        debug1("(%d,%d)で詰みました 深さは%dです\n",w,h,depth+1);
        if(maxtile<depth+1){
            maxtile=depth+1;
        }
    }
    debug1("(%d,%d)で 深さ %d での探索完了→(%d,%d)を埋める\n",
    w,h,depth,w,h);
    G[h][w]=1;
    GS;
}

int main(void){
    initial();
    cin >> M;
    cin >> N;
    vector<vector<int>> G(N+2,vector<int>(M+2,2));
    for(int j=0;j<N;j=j+1){
        for(int k=0;k<M;k=k+1){
            cin >> G[j+1][k+1];
        }
    }
    int result;
    for(int h=0;h<(int)G.size();h=h+1){
        for(int w=0;w<(int)G[0].size();w=w+1){
            if(G[h][w]==1){
                debug1("(%d,%d) 検索開始!!\n",w,h);
                dfs(G,h,w,0);
            }
        }
    }
    cout << maxtile << "\n" << flush;
    return 0;
}
