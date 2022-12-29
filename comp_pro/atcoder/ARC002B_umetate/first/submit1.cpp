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

static const int LEN=10;
static const string Y="YES\n";
static const string N="NO\n";

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool isExit_o(vector<vector<char>> &G){
    int W = G[0].size();
    int H = G.size();
    bool result = false;
    for(int jh=0;jh<H;jh=jh+1){
        for(int kw=0;kw<W;kw=kw+1){
            if(G[jh][kw] == 'o'){
                result = true;
            }
        }
    }
    return result; // Vしか無い場合は最初の設定通りfalseを返す
}
void GCopy(vector<vector<char>> &G,vector<vector<char>> &G2){
    for(int x=0;x<G.size();x=x+1){
        copy(G[x].begin(),G[x].end(),G2[x].begin());
    }
    /**
    for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            G2[j][k]=G[j][k];
        }
    }**/
}

void GShow(vector<vector<char>> &G){
    for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            debug("%c",G[j][k]);
        }
        debug("\n");
    }
}

void dfs(vector<vector<char>> &G,int &sx,int &sy){
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    G[sx][sy] = 'V';
    int cx = sx;
    int cy = sy;
    stack<pair<int,int>> ST;
    ST.push(make_pair(cx,cy));
    while(!ST.empty()){
        pair<int,int> thispos = ST.top(); // Last Get
        ST.pop(); // Last throw
        for(int j=0;j<4;j=j+1){
            // 4方向に進める
            int nx = thispos.first+dx[j];
            int ny = thispos.second+dy[j];
            // 次に行けるかチェック
            // (1) 0 未満になったらアウト
            if( nx < 0 || ny < 0 ){
                continue;
            }
            // 枠を超えたのであうと
            if( 10 <= nx || 10 <= ny ){
                continue;
            }
            // 海なのでアウト
            if( G[nx][ny] == 'x' ){
                continue;
            }
            // すでに検索済みなのでアウト
            if( G[nx][ny] == 'V' ){
                continue;
            }
            // 問題がないならVを埋めてスタックに入れる→次の検索対象
            G[nx][ny] = 'V';
            ST.push(make_pair(nx,ny));
        }

    }
}

bool solver(vector<vector<char>> &G,vector<pair<int,int>> &lands)
{
    vector<vector<char>> GFree(LEN,vector<char>(LEN));
    bool answer=false;
    for(int j=0;j<lands.size();j=j+1){
        GCopy(G,GFree);
        pair<int,int> toLand=lands.at(j);
        int toLandx=toLand.first;
        int toLandy=toLand.second;
        bool result=false;
        dfs(GFree,toLandx,toLandy);
        if(!isExit_o(GFree)){
            return true;
        }
       }
    return false;
}

int main(void){
    initial();
    // 島の地図G
    vector<vector<char>> G(LEN,vector<char>(LEN));
    // 現在の島の位置
    vector<pair<int,int>> LANDS;
    // 地図を取り込む
    for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            cin >> G[j][k];
        }
    }
   for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            if(G[j][k]=='x'){
               LANDS.push_back(make_pair(j,k));
            }
        }
   }
   if(solver(G,LANDS)){
        cout << Y << flush;
   }
   else{
    cout << N << flush;
   }

    return 0;
}
