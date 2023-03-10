#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
    // 幅優先探索開始
    queue<pair<int,int>> que;
    que.push(make_pair(sy,sx));
    L[sy][sx]=0;
    vector<int> dh = {1,0,-1,0};
    vector<int> dw = {0,1,0,-1};
    while(que.empty()==false){
        pair<int,int> nowpos=que.front();
        if(nowpos.first == gy && nowpos.second == gx){
            break;
        }
        bool is_go=false;
        for(int j=0;j<4;j=j+1){
            int ny,nx;
            ny = nowpos.first+dh[j];
            nx = nowpos.second+dw[j];
            if(D[ny][nx]==-1){ // 訪問できない
                continue;
            }
            else{
                if(D[ny][nx]==1){ // すでに訪問済み
                    continue;
                }else
                {
                    L[ny][nx]=L[nowpos.first][nowpos.second]+1;
                    is_go=true;
                    que.push(make_pair(ny,nx));
                }
            }
        }
        D[nowpos.first][nowpos.second]=1;
        que.pop();
    }
    cout << L[gy][gx] << "\n" << flush;
    return 0;
}

