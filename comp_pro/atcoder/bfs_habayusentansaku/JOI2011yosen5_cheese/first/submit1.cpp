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

// 大域変数
vector<vector<char>> G(10000,vector<char>(10000,'X'));
vector<vector<int>> dir(10000,vector<int>(10000,yamaMAX_INT));
vector<POS> fact(10,make_pair(0,0));


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
    // TODO: 2023年3月23日 後は個々に幅優先探索を行えば良い
    return 0;

}
