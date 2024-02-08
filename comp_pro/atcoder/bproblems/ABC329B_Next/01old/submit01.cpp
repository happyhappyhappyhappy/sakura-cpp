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

bool compareDescending(int a,int b){
    return a>b || (a==b && a > b);
}
int partition(vector<int>& X,int low,int high){
    int pivot=X[high];
    int k=low-1;
    for(int j=low;j<=high-1;j=j+1){
        if(compareDescending(X[j],pivot)){
            k=k+1;
            swap(X[k],X[j]);
        }
    }
    swap(X[k+1],X[high]);
    return (k+1);
}


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    return 0;
}
