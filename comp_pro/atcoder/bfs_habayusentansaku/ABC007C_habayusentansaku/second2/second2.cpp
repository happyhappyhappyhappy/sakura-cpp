#include<bits/stdc++.h>
#ifdef LOCAL
#include"../debug/debug.h"
#include"../debug/t_debug.h"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
using pos=pair<int,int>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

// 大域変数

vector<vector<char>> G(1000,vector<char>(1000,'X'));
vector<vector<int>> dist(1000,vector<int>(1000,yamaMAX_INT));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void mapShow(int R,int C){
    for(int j=0;j<=R+1;j=j+1){
        for(int k=0;k<=C+1;k=k+1){
            debug(" %c",G[j][k]);
        }
        debug("\n");
    }
}
void distShow(int R,int C){
    for(int j=0;j<=R+1;j=j+1){
        for(int k=0;k<=C+1;k=k+1){
            if(dist[j][k]==yamaMAX_INT){
                debug("  *");
            }
            else{
                debug("%3d",dist[j][k]);
            }
        }
        debug("\n");
    }
    debug("\n");
}

int bfs(int H,int W,int sh,int sw,int gh,int gw){
    int result=0;
    vector<int> dh={1,0,-1, 0};
    vector<int> dw={0,1, 0,-1};
    queue<pair<int,int>> Q;
    pos spos=make_pair(sh,sw);
    Q.push(spos);
    dist[spos.first][spos.second]=0;
    while(Q.empty()==false){
        pos npos=Q.front();
        if(npos.first == gh && npos.second == gw){
            // ゴール
            result = dist[gh][gw];
            break;
        }
        for(int j=0;j<4;j=j+1){
            pos nextp = make_pair(npos.first+dh[j],npos.second+dw[j]);
            int h=nextp.first;
            int w=nextp.second;
            if(G[h][w] != '.'){
                continue;
            }
            if(dist[h][w]!=yamaMAX_INT){
                continue;
            }
            dist[h][w]=1+dist[npos.first][npos.second];
            Q.push(nextp);
        }
        // distShow(H,W);
        Q.pop();
    }
    return result;
}

int main(void){
    initial();
    int R,C,sh,sw,gh,gw;
    int answer;
    cin >> R >> C >> sh >> sw >> gh >> gw;
    for(int j=1;j<=R;j=j+1){
        for(int k=1;k<=C;k=k+1){
            cin >> G[j][k];
        }
    }
    mapShow(R,C);
    distShow(R,C);
    answer = bfs(R,C,sh,sw,gh,gw);
    cout << answer << "\n" << flush;
    return 0;
}
