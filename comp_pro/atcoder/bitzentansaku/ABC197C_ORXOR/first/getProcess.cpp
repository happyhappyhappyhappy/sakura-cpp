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
    for(int j=1;j<((1<<NK)-1);j=j+1){
        ORList.push_back(0);
        for(int k=0;k<NK;k=k+1){
            int Fl=j>>k;
            if((FL & 1) == 1){// 区切る
                XORTable.push_back(ORList);


            }
        }
    }

    return 0;
}
