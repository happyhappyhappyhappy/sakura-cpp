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
const ll yamaMAX_LL = 1LL << 58;

vector<vector<long long>> DP(0,vector<long long>(21,0));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
/**
void showDP(){
    int H = (int)DP.size();
    int W = (int)DP[0].size();
    for(int h=0;h<H;h=h+1){
        for(int w=0;w<W;w=w+1){
            debug("  %lld",DP[h][w]);
        }
        debug("\n");
    }
    debug("\n\n");
}
**/
ll solver(vector<int> &A,int &R){
    int dp_elem=(int)A.size();
    DP.assign(dp_elem,vector<ll>(21,0LL));
    DP[0][A[0]]=1LL;
    for(int j=0;j<(dp_elem-1);j=j+1){
        for(int X=0;X<=20;X=X+1){
            if((X+A[j+1])<=20){
                DP[j+1][X+A[j+1]]=DP[j+1][X+A[j+1]]+DP[j][X];
            }
            if(0<=(X-A[j+1])){
                DP[j+1][X-A[j+1]]=DP[j+1][X-A[j+1]]+DP[j][X];
            }
        }
//     showDP();
    }
    return DP[dp_elem-1][R];
}

int main(void){
    initial();
    int N,R;
    cin >> N;
    vector<int> V(N-1,0); // 最後の数字は結果なので分ける
    for(int j=0;j<(int)V.size();j=j+1){
        cin >> V[j];
    }
    cin >> R;
    cout << solver(V,R) << "\n" << flush;
    return 0;
}
