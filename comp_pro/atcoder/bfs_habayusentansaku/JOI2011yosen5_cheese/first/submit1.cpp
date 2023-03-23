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
using POS=pair<int,int>
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

// 大域変数
vector<vector<char>> G;
vector<ll> dir;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int H,W,N;
    cin >> H >> W >> N;
    G.assign(H+2,vector<char>(W+2,'#'));
    dir.assign(N+1);
    for(int j=0;j<H;j=j+1){
        string tmpstr;
        for(int k=0;k<W;k=k+1){
            G[j+1][k+1] = tmpstr[k];
        }
    }
    for(int j=0;j<H+2;j=j+1){
        // TODO: ここから for(int k=0;k<W+)
    }
    return 0;
}
