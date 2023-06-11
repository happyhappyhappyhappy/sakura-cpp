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
// 2023-06-10 19:11:35
// XORTableとORListのテスト->実践で使えるか
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
int main(void){
    initial();
    int N=0;
    cin >> N;
    vector<int> A(N,-1);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    int NK=N-1;
    vector<vector<int>> XORTable;
    vector<int> ORList;
    // for(int j=0;j<(1<<NK);j=j+1){ 全部探索します
    for(int j=0;j<((1<<NK)-1);j=j+1){
        debug("===== %4d の場合の分布 =====\n",j);
        ORList.push_back(A[0]);
        for(int k=0;k<NK;k=k+1){
            int Fl=j>>k;
            if((Fl & 1) == 1){// 区切らない
                ORList.push_back(A[k+1]);
            }
            else{// 区切る
                XORTable.push_back(ORList);
                ORList.clear();
                ORList.push_back(A[k+1]);
            }
        }
        XORTable.push_back(ORList);
        ORList.clear(); // 使い回しのため一旦クリア
        debug("XORTABLEの列数=%3d\n",(int)XORTable.size());
        for(int k=0;k<(int)XORTable.size();k=k+1){
            ORList=XORTable[k];
            for(int m=0;m<(int)ORList.size();m=m+1){
                debug(" %3d",ORList[m]);
            }
            debug("\n");
            ORList.clear();
        }
        XORTable.clear(); // これをしないと前と同じテストが入ってしまう
    }
    return 0;
}
