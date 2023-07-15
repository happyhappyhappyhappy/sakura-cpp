#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif

using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
// グローバル変数
int N; // 頂点の個数
vector<int> C;
vector<vector<int>> G;
vector<int> DC;
vector<bool> R;
vector<bool> ANS;

int maxColor(vector<int> &c,int n){
    int res=-1;
    for(int j=0;j<=n;j=j+1){
        if(res <= c[j]){
            res = c[j];
        }
    }
    return res;
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // グローバル配列の初期化
    cin >> N;
    C.assign(N+1,0);
    for(int j=1;j<=N;j=j+1){
        cin >> C[j];
    }
    G.resize(N+1);
    int AM=maxColor(C,N);
    DC.assign(AM+1,0);
    R.assign(N+1,false);
    ANS.assign(N+1,true);
    ANS[0]=false;
}
int main(void){
    initial();
    // TODO: ここでグローバル変数がきちんと代入されているか確認
    // 2023-7-15
    return 0;
}
