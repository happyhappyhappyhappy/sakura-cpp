#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug1(...) 42
#define debug2(...) 42
#define debug(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

int H,W,sh,sw,gh,gw;
vector<vector<char>> G(1000,vector<char>(1000,'X'));
vector<vector<int>> dist(1000,vector<int>(1000,-1));
vector<int> dh={-1,0,1,0};
vector<int> dw={0,1,0,-1};


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void GShow(int H,int W){
    for(int j=1;j<=H;j=j+1){
        for(int k=1;k<=W;k=k+1){
            debug1(" %c",G[j][k]);
        }
        debug1("\n");
    }
    debug1("\n");
}

int main(void){
    initial();
    cin >> H >> W;
    cin >> sh >> sw;
    cin >> gh >> gw;
    for(int j=1;j<=H;j=j+1){
        for(int k=1;k<=W;k=k+1){
            cin >> G[j][k];
        }
    }
    GShow(H,W);
    for(int j=1;j<=H;j=j+1){
        for(int k=1;k<=W;k=k+1){
            dist[j][k]=yamaMAX_INT;
        }
    }
    queue<pii> Q;
    // first pos
    Q.push(make_pair(sh,sw));
    dist[sh][sw]=0;
    while(Q.empty()==false){
        pii npos = Q.front();Q.pop();
        debug(npos);
        if(npos.first == gh && npos.second == gw){
            debug1("ゴール ( %d , %d )に到達しました\n",gh,gw);
            break;
        }
        for(int j=0;j<4;j=j+1){//
            int nh = npos.first+dh[j];
            int nw = npos.second+dw[j];
            if(G[nh][nw]!='.'){
                debug1(" ( %d , %d )には行くことが出来ない\n",nh,nw);
                continue;
            }
            if(dist[nh][nw]!=yamaMAX_INT){
                debug1(" ( %d , %d )はすでに通ってしまった\n",nh,nw);
                continue;
            }
            debug1(" ( %d , %d )は行けるのでコマを進める\n",nh,nw);
            dist[nh][nw]=dist[npos.first][npos.second]+1;
            Q.push(make_pair(nh,nw));
        }
    }
    cout << dist[gh][gw] << "\n" << flush;
    return 0;
}


