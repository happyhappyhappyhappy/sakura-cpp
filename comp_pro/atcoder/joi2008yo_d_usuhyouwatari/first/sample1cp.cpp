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

vector<vector<int>> Grid(100,vector<int>(100,0));
int max_area=-1;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int h,w;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfs(vector<vector<int>> &Grid,int j,int k,int cnt){
    debug("探索(%d,%d) 割った数 %dで次の探索をします\n",j,k,cnt);
    Grid[j][k]=0; // 一旦割っておく
    bool step_fg=false;
    for(int x=0;x<4;x=x+1){
        int nj = j + dx[x];
        int nk = k + dy[x];
        if(nj < 0 || h<= nj || nk < 0 || w<=nk){
            continue;
        }
        if(Grid[nj][nk]){
            debug("\t(%d,%d)に飛びます\n",nj,nk);
            dfs(Grid,nj,nk,cnt+1);
            step_fg=true;
        }
    }
    if(step_fg==false){
        chmax(max_area,cnt);
    }
    cnt = cnt-1;
    Grid[j][k]=1;
}

int main(void){
    cin >> h >> w;
    for(int j=0;j<h;j=j+1){
        for(int k=0;k<w;k=k+1){
            int a;
            cin >> a;
            Grid[j][k] = a;
        }
    }
    initial();
    for(int j=0;j<h;j=j+1){
        for(int k=0;k<w;k=k+1){
            int cnt = 1;
            if(Grid[j][k]){
                dfs(Grid,j,k,cnt);
            }
        }
    }
    cout << max_area << "\n" << flush;
    return 0;

}

