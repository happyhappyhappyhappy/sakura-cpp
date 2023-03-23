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
            debug1(" %c",G[j][k]);
        }
        debug1("\n");
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
    }
}

int main(void){
    initial();
    int R,C,sh,sw,gh,gw;
    cin >> R >> C >> sh >> sw >> gh >> gw;
    for(int j=1;j<=R;j=j+1){
        for(int k=1;k<=C;k=k+1){
            cin >> G[j][k];
        }
    }
    mapShow(R,C);
    distShow
    return 0;
}
