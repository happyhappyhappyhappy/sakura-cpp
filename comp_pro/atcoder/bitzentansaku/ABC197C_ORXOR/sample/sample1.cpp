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
// 検証:pythonのlistみたいにvector<int>が作れるか確認
// 2023-06-10 18:20:18
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    vector<vector<int>> XORT;
    vector<int> ORL;
    ORL.push_back(0);
    ORL.push_back(1);
    ORL.push_back(2);
    XORT.push_back(ORL);
    ORL.clear();
    ORL.push_back(3);
    ORL.push_back(4);
    ORL.push_back(5);
    XORT.push_back(ORL);
    ORL.clear();
    ORL.push_back(6);
    ORL.push_back(7);
    XORT.push_back(ORL);
    for(int j=0;j<(int)XORT.size();j=j+1){
        vector<int> O_ORL=XORT[j];
        for(int k=0;k<(int)O_ORL.size();k=k+1){
            cout << O_ORL[k] << " ";
        }
        cout << "\n" << flush;
    }

    return 0;
}
