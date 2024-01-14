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
int main(void){
    initial();
    int H,W,N;
    cin >> H >> W >> N;
    vector<int> X(N);
    vector<int> Y(N);
    for(int j=0;j<N;j=j+1){
        cin >> X[j] >> Y[j];
    }
    vector<int> Xc=X;
    vector<int> Yc=Y;
    // Xc のソートとW削除
    sort(Xc.begin(),Xc.end());
    Xc.erase(unique(Xc.begin(),Xc.end()),Xc.end());
    // Yc のソートと削除
    sort(Yc.begin(),Yc.end());
    Yc.erase(unique(Yc.begin(),Yc.end()),Yc.end());
    for(int j=0;j<N;j=j+1){
        int xpos=lower_bound(Xc.begin(),Xc.end(),X[j])-Xc.begin();
        int ypos=lower_bound(Yc.begin(),Yc.end(),Y[j])-Yc.begin();
        cout << xpos+1 << " " << ypos+1 << "\n" << flush;
    }
    return 0;
}
