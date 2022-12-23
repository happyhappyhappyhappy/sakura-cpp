#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

// 初心者としてグローバル変数
int Hy,Wx; // 地図の高さ、幅。yとxはイメージを二次元にするため
bool seen[510][510]; // 見ました印
int sy,sx; // スタート地点
int gy,gx; // ゴール地点

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int y=0;y<510;y=y+1){
        for(int x=0;x<510;x=x+1){
            seen[y][x]=false;
        }
    }
}

bool posNGCheck(int y,int x,vector<vector<char>> &G){
    if(y<0){
        return true;
    }
    if(x<0){
        return true;
    }
    if(Hy<=y){
        return true;
    }
    if(Wx<=x){
        return true;
    }
    if(G[y][x] == '#'){
        return true;
    }
    return false;
}

void dfs(int y,int x,vector<vector<char>> &G){
    seen[y][x] = true; // 検索済みのマーク
    int dy[4]={1,0,-1,0};
    int dx[4]={0,1,0,-1};
    for(int j=0;j<4;j=j+1){
        int next_x,next_y;
        next_y=y+dy[j];
        next_x=x+dx[j];
        if(posNGCheck(next_y,next_x,G)){
            continue;
        }
        if(seen[next_y][next_x]){
            continue;
        }
        dfs(next_y,next_x,G);
    }
}

bool solver(vector<vector<char>> &G){
    dfs(sy,sx,G);
    return seen[gy][gx];
}

int main(void){
    initial();
    cin >> Hy >> Wx;
    vector<vector<char>> G(Hy,vector<char> (Wx));
    for(int jy=0;jy<Hy;jy=jy+1){
        for(int kx=0;kx<Wx;kx=kx+1){
            char thing;
            cin >> thing;
            G[jy][kx]=thing;
            if(thing == 'g'){
                gy=jy;
                gx=kx;
            }
            if(thing == 's'){
                sy=jy;
                sx=kx;
            }
        }
    }
    if(solver(G)){
        cout << "Yes\n" << flush;
    }
    else{
        cout << "No\n" << flush;
    }
    return 0;
}

