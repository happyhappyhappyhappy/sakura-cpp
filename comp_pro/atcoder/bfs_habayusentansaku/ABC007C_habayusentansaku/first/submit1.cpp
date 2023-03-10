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
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;
typedef pair<int,int> pii;
int H,W,sh,sw,gh,gw;

vector<vector<char>> c(100,vector<char>(100,'*'));
vector<vector<int>> dist(100,vector<int>(100,0));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void cShow(vector<vector<char>> C,int H,int W){
    for(int j=1;j<=H;j=j+1){
        for(int k=1;k<=W;k=k+1){
            debug1(" %c",C[j][k]);
        }
        debug1("\n");
    }
}
void dShow(vector<vector<int>> D,int H,int W){
    for(int j=1;j<=H;j=j+1){
        for(int k=1;k<=W;k=k+1){
            if(D[j][k]==yamaMAX_INT){
                debug1("   *");
            }
            else{
                debug1("%4d",D[j][k]);
            }
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
            cin >> c[j][k];
            dist[j][k]=yamaMAX_INT;
        }
    }
    vector<int> dh={1,0,-1,0};
    vector<int> dw={0,1,0,-1};
    queue<pii> Q;
    dist[sh][sw]=0;
    Q.push(make_pair(sh,sw));
    while(Q.empty()==false){
        pii pos=Q.front();
        if(pos.first == gh && pos.second == gw){
            // debug1("ゴール (%d,%d)に到達しました\n",pos.first,pos.second);
            break;
        }
        Q.pop();
        for(int j=0;j<4;j=j+1){
            int next_h=pos.first+dh[j];
            int next_w=pos.second+dw[j];
            if(c[next_h][next_w]!='.'){
                continue;
            }
            if(dist[next_h][next_w]!=yamaMAX_INT){
                continue;
            }
            dist[next_h][next_w]=dist[pos.first][pos.second]+1;
            Q.push(make_pair(next_h,next_w));
        }
        // dShow(dist,H,W);
    }
    cout << dist[gh][gw] << "\n" << flush;
    return 0;
}

