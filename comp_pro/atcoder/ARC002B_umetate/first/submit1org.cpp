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
// 2022年12月26日スクラップビルドした残り
static const int LEN=10;
static const string Y="YES\n";
static const string N="NO\n";

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void GCopy(vector<vector<char>> &G,vector<vector<char>> &G2){
    for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            G2[j][k]=G[j][k];
        }
    }
}

void dfs(vector<vector<char>> &G,int j,int k){
    int dj[]={0,0,1,-1};
    int dk[]={1,-1,0,0};
    stack<pair<int,int>> ST;
    G[j][k] = 'V';
    debug("-----(%d,%d)を埋め立てた開始図-----\n",j,k);
    for(int x=0;x<LEN;x=x+1){
        for(int y=0;y<LEN;y=y+1){
            debug("%c",G[x][y]);
        }
        debug("\n");
    }
    ST.push(make_pair(j,k));
    while(!ST.empty()){
        pair<int,int> pos = ST.top();
        ST.pop();
        for(int x=0;x<4;x=x+1)
        {
            int nextj = pos.first+dj[x];
            int nextk = pos.second+dk[x];
            if( 0 <= nextj &&
            nextj < 10 &&
            0 <= nextk &&
            nextk < 10
            ){
                if(G[nextj][nextk] == 'o'){
                    G[nextj][nextk] = 'V';
                    ST.push(make_pair(nextj,nextk));
                    debug("(%d,%d)->OK\n",nextj,nextk);
                }
            }
            else{
                debug("(%d,%d)->NG\n",nextj,nextk);
            }
        }
    }
    debug("-----(%d,%d)を埋め立てた場合:終了図-----\n",j,k);
    for(int x=0;x<LEN;x=x+1){
        for(int y=0;y<LEN;y=y+1){
            debug("%c",G[x][y]);
        }
        debug("\n");
    }
}

bool dfsmain(vector<vector<char>> &G){
    for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            if(G[j][k] == 'o'){
                dfs(G,j,k);
            }
        }
    }

    return false;
}

bool solver(vector<vector<char>> &G,queue<pair<int,int>> &lands){
    vector<vector<char>> GFree(LEN,vector<char>(LEN));
    bool answer=false;
    /**
    for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            debug("%c",GFree[j][k]);
        }
        debug("\n");
    }
    **/
    while(!lands.empty()){
        GCopy(G,GFree);
        pair<int,int> toLand=lands.front();
        // debug("->(%d,%d)",toLand.first,toLand.second);
        lands.pop();
        GFree[toLand.first][toLand.second]='o';
        bool result=false;
        result = dfsmain(GFree);
        if(result){
            answer=true;
            break; // 島になっていた
        }
    }
    // debug("\n");
    return true;
}

int main(void){
    initial();
    // 島の地図G
    vector<vector<char>> G(LEN,vector<char>(LEN));
    // 現在の島の位置
    queue<pair<int,int>> LANDS;
    // 地図を取り込む
    for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            cin >> G[j][k];
        }
    }
    // 正しく取れているか＆'%c'で出力できるか確認
    for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            debug("%c",G[j][k]);
        }
        debug("\n");
    }
   for(int j=0;j<LEN;j=j+1){
        for(int k=0;k<LEN;k=k+1){
            if(G[j][k]=='x'){
               LANDS.push(make_pair(j,k));
            }
        }
   }
   /**
    * queueのテスト
   */
  /**
    while(!LANDS.empty()){
        pair<int,int> pos;
        pos=LANDS.front();
        debug("-> (%d,%d)",pos.first,pos.second);
        LANDS.pop();
    }
    debug("\n");
    **/

// 本体
   if(solver(G,LANDS)){
        cout << Y << flush;
   }
   else{
    cout << N << flush;
   }

    return 0;
}


