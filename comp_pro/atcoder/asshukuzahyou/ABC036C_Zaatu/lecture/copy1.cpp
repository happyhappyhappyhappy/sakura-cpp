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
void vectorLook(vector<int> &X){
    int N = (int)X.size();
    for(int j=0;j<N;j=j+1){
        debug("%d",X[j]);
        if(j != N-1){
            debug(" ");
        }
    }
    debug("\n");
}
int main(void){
    initial();
    int N;
    cin >> N;
    vector<int> A(N,0);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    debug("-----Aの中身-----\n");
    vectorLook(A);
    vector<int> B=A; // AをBにコピー
    debug("-----Bの中身-----\n");
    vectorLook(B);
    sort(B.begin(),B.end());
    debug("-----Bのソート後-----\n");
    vectorLook(B);
    debug("-----Bの重複除去-----\n");
    B.erase(unique(B.begin(),B.end()),B.end());
    vectorLook(B);
    // for(auto& b:B){
    //     cout << b << " ";
    // }
    // cout << "\n" << flush;
    vector<int> res((int)A.size(),0);
    for(int j=0;j<(int)A.size();j=j+1){
        res[j]=lower_bound(B.begin(),B.end(),A[j])-B.begin();
    }
    debug("-----Aの座標圧縮結果-----\n");
    vectorLook(res);
    for(auto& r:res){
        cout << r << " ";
    }
    cout << "\n" << flush;
    return 0;
}
