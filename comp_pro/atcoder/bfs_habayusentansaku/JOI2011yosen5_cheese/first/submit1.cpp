#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug/debug.h"
#include"/code/sakura-cpp/comp_pro/debug/t_debug.h"
#else
#define debug1(...) 42
#define debug2(...) 42
#define debug(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
using POS=pair<int,int>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;
const int MAXSIZE=1010;

// 大域変数
vector<vector<char>> G(MAXSIZE,vector<char>(MAXSIZE,'X'));
vector<vector<int>> dir(MAXSIZE,vector<int>(MAXSIZE,yamaMAX_INT));
vector<POS> fact(10,make_pair(0,0));
vector<int> dh={1,0,-1,0};
vector<int> dw={0,1,0,-1};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showG(int R,int W){
    for(int j=0;j<R+2;j=j+1){
        for(int k=0;k<W+2;k=k+1){
            debug(" %c",G[j][k]);
        }
        debug("\n");
    }
    debug("\n");
}

void showFact(int N){
    for(int j=1;j<=N;j=j+1){
        int fromh=fact[j-1].first;
        int fromw=fact[j-1].second;
        int toh = fact[j].first;
        int tow = fact[j].second;
        debug("%d : (%d,%d)->(%d,%d)\n",j,fromh,fromw,toh,tow);
    }
}

int main(void){
    initial();
    int H,W,N;
    cin >> H >> W >> N;
    for(int j=1;j<=H;j=j+1){
        for(int k=1;k<=W;k=k+1){
            cin >> G[j][k];
        }
    }
    showG(H,W);
    for(int j=0;j<=H;j=j+1){
        for(int k=0;k<=W;k=k+1){
            if(G[j][k]=='S'){
                fact[0]=make_pair(j,k);
            }
        }
    }
    for(int j=1;j<=N;j=j+1){
        char nowchar= j+'0';
 //       debug("今調べようとしているのは %c です\n",nowchar);
        for(int k=0;k<=H;k=k+1){
            for(int m=0;m<=W;m=m+1){
                if(G[k][m] == nowchar){
//                    debug("%d があるのは (%d,%d)でした\n",j,k,m);
                    fact[j]=make_pair(k,m);

                }
            }
        }
    }
    showFact(N);
    int dist=0;
    for(int j=0;j<N;j=j+1){
        int fromh=fact[j].first;
        int fromw=fact[j].second;
        int toh = fact[j+1].first;
        int tow = fact[j+1].second;
        // dirの再初期化を行う
        dir.assign(MAXSIZE,vector<int>(MAXSIZE,yamaMAX_INT));
        queue<POS> que;
        que.push(make_pair(fromh,fromw));
        dir[fromh][fromw]=0;
        while(que.empty()==false){
            POS nowpos=que.front();
            int nowh=nowpos.first;
            int noww=nowpos.second;
            if(nowh==toh && noww==tow){//ゴールにたどり着いた
                dist=dist+dir[nowh][noww];
                break;
            }
            for(int j=0;j<4;j=j+1){
                int nexth=nowh+dh[j];
                int nextw=noww+dw[j];
                if(G[nexth][nextw]=='X')
                {
                    continue;
                }
                if(dir[nexth][nextw]==yamaMAX_INT){
                    dir[nexth][nextw]=dir[nowh][noww]+1;
                    que.push(make_pair(nexth,nextw));
                }
            }
            que.pop();
        }
    }
    cout << dist << "\n" << flush;
    return 0;

}
