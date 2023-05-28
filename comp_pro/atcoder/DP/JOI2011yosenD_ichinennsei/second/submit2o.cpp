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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int Xall=0;// 取り得る全部の値
    cin >> Xall;
    int X=Xall-1; // 足し引きする合計数
    vector<int> V(X,0); // 足し引き要素
    int R=0; // 確認する結果
    for(int j=0;j<X;j=j+1){
        cin >> V[j];
    }
    cin >> R;
    for(int j=0;j<X;j=j+1)// 要はこれを得たい組み合わせをアウトプット

    return 0;
}
