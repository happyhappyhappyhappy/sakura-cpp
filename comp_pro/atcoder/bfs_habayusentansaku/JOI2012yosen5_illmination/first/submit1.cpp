#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
using POS=pair<int,int>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

// 大域変数
vector<vector<int>> G;
vector<vector<int>> visited;
int H,W;
static vector<int> dh_even={-1,0,1,1,0,-1};
static vector<int> dw_even={0,1,1,-1,-1,-1};
static vector<int> dh_odd={-1,0,1,1,0,-1};
static vector<int> dw_odd={1,1,1,0,-1,0};
static vector<char*> dhdwto={"右上へ","真右へ","右下へ",
"左下へ","真左へ","左上へ"};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void ShowG(int H,int W,vector<vector<int>> &G){
    for(int j=0;j<H;j=j+1){
        for(int k=0;k<W;k=k+1){
            debug(" %d",G[j][k]);
        }
        debug("\n");
    }
    debug("\n\n");
}
bool isgo(int h,int w,int H,int W){
    if(h < 0 || w < 0){
        return false;
    }
    if(H <= h || W <= w){
        return false;
    }
    return true;
}

int main(void){
    initial();
    cin >> W >> H;
    G.assign(H+2,vector<int>(W+2,0));
    visited.assign(H+2,vector<int>(W+2,0));
    for(int h = 1 ; h<=H ; h=h+1){
        for(int w=1;w<=W;w=w+1 ){
            cin >> G[h][w];
        }
    }
    ShowG(H+2,W+2,G);
    queue<POS> Q ;
    Q.push(make_pair(0,0));
    int answer=0;
    while(Q.empty()==false){
        POS nowpos = Q.front();
        Q.pop();
        int nowposh = nowpos.first;
        int nowposw = nowpos.second;
        debug("現在、(H,W)=(%d,%d)にいます\n",nowposh,nowposw);
        if(visited[nowposh][nowposw] == 1){
            debug("(%d,%d)は通過済み\n",nowposh,nowposw);
            continue;
        }
        visited[nowposh][nowposw]=1;
        for(int j=0;j<6;j=j+1){
            int nextposh,nextposw;
            if(nowposh % 2 == 1 ){
                nextposh = nowposh+dh_odd[j];
                nextposw = nowposw+dw_odd[j];
            }
            else{
                nextposh = nowposh+dh_even[j];
                nextposw = nowposw+dw_even[j];
            }
            if(isgo(nextposh,nextposw,H+2,W+2)==false){
             //   debug("(%d,%d)は枠内ではないので却下\n",nextposh,nextposw);
                continue;
            }
            else{
                if(G[nextposh][nextposw]==1){
                    answer = answer +1;
                    debug("     %s 処理をしたら(%d,%d)に衝突した\n 現在の壁 %d\n",
                    dhdwto[j],nextposh,nextposw,answer);
                }
                else{
                    if(visited[nextposh][nextposw]==0){
                        Q.push(make_pair(nextposh,nextposw));
                    }
                }
            }
        }
        visited[nowposh][nowposw]=1;
 // 使用済み
    }
    ShowG(H+2,W+2,visited);
    cout << answer << "\n" << flush;
    return 0;
}
