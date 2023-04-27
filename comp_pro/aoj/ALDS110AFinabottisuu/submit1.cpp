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
vector<ll> D(45,0);

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    D[0]=1;
    D[1]=1;
    for(int j=2;j<45;j=j+1){
        D[j]=D[j-1]+D[j-2];
    }
}

ll solver(int N){
    return D[N];
}

int main(void){
    initial();
    int N;
    cin >> N;
    cout << solver(N) << "\n" << flush;
    return 0;
}

