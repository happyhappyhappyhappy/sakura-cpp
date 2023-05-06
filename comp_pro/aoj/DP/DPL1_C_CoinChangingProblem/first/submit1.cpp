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
const int INF=60000;

vector<vector<int>> dp(25,vector<int>(60000,0));

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int sn=0;sn<60000;sn=sn+1){
        dp[0][sn]=INF;
    }
    for(int mc=0;mc<25;mc=mc+1){
        dp[mc][0]=0;
    }
}

int main(void){
    initial();
    int MC,SN;
    cin >> SN >> MC;
    vector<int> coin(25,0);
    for(int j=0;j<=MC;j=j+1){
        cin >> coin[j];
    }
    for(int j=1;j<=MC;j=j+1){
        // TODO: 2023/05/06 ここで打ち切り 2023-05-06 19:20:34
    }
    return 0;
}
