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
using pint=pair<int,int>;
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
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> where(N);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
        A[j]=A[j]-1;
        where[A[j]]=j;
    }
    vector<pint> res;
    for(int j=0;j<N-1;j=j+1){
        if(A[j]==j){
            continue;
        }
        int k=where[j];
        swap(where[A[j]],where[A[k]]);
        swap(A[j],A[k]);
        res.emplace_back(j,k);
    }
    cout << res.size() << endl;
    for(auto [j,k]:res){
        cout << j+1 << " " << k+1 << endl;
    }
    return 0;
}
