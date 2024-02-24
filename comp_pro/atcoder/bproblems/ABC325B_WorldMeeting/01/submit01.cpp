#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/lib/dump.hpp"
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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int solver(int N,vector<int> &W,vector<int> &X){
    int answer=0;
    vector<int> cnt(24,0);
    for(int j=0;j<N;j=j+1){
        debug("拠点 %d は 従業員 %d 人で、標準とのズレは +%d 時間です\n",j+1,W[j],X[j]);
        cnt[X[j]]=cnt[X[j]]+W[j];
    }
    for(int j=0;j<24;j=j+1){
        debug("+%d 時間の従業員 %d\n",j,cnt[j]);
    }
    for(int j=0;j<24;j=j+1){
        int nowWorker=0;
        for(int k=9;k<18;k=k+1){
            nowWorker=nowWorker+cnt[(j+k)%24];
        }
        debug("+%d 時間ずれの場合にあつまれる従業員数は %d 人\n",j,nowWorker);
        if(answer<nowWorker){
            answer=nowWorker;
        }
    }
    return answer;
}
int main(void){
    initial();
    int N;
    cin >> N;
    vector<int> W(N,0);
    vector<int> X(N,0);
    for(int j=0;j<N;j=j+1){
        cin >> W[j] >> X[j];
    }
    cout << solver(N,W,X) << endl;
    return 0;
}
