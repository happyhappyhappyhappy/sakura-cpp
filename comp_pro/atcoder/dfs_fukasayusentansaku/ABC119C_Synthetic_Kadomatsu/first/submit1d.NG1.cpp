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
// ABC119C Synthetic Kadomatu 再帰関数利用編
// グローバル変数
int N; // 材料の竹の数
int A,B,C; // 完成させたい竹の長さ
vector<int> L; // 材料の竹の長さ

void showData(void){
    debug("竹の本数 : %d , 必要な竹の長さ %d , %d , %d \n",N,A,B,C);
    debug("利用する竹 ");
    for(auto &e: L){
        debug(" %d ",e);
    }
    debug("\n");
}
int dfs(int n,int a,int b,int c){
    int nowans=0;
    if(n==N){
        debug("すべての竹を利用したので増加魔法＋減少魔法を計算します\n");
        if(min(a,b,c)>0){
            debug("a = %d , b = %d , c = %d\n",a,b,c);
            debug("内容はともかく計算できそうなので求めます\n");
        }else{
//  2023-07-08 19:31:23 n==Nのロジックをまず書きましょう
        }
    }
    return nowans;
}
int solver(void){
    int result=0;
    showData();
    result = dfs(0,0,0,0);
    return result;
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> N;
    cin >> A >> B >> C;
    L.resize(N);
    for(int j=0;j<N;j=j+1){
        cin >> L[j];
    }
    cout << solver() << "\n" << flush;
    return 0;
}
