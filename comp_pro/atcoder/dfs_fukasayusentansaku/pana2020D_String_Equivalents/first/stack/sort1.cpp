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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    vector<string> X;
    int N=3;
    cin >> N;
    for(int j=0;j<N;j=j+1){
        string x;
        cin >> x;
        X.push_back(x);
    }
    sort(X.begin(),X.end());
    for(int j=0;j<int(X.size());j=j+1){
        cout << X[j] << "\n" << flush;
    }
    return 0;
}
