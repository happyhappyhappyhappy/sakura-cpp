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
    int N,C;
    cin >> N >> C;
    long long all_times=pow(10,9)+10;
    vector<long long> P(all_times,0);
    vector<long long> Acc(all_times+1,0);
    for(int j=0;j<N;j=j+1){
        long long ftime,ttime,c;
        cin >> ftime >> ttime >> c;
        P[ftime]=P[ftime]+c;
        P[ttime]=P[ttime+1]-c;
    }
    for(int j=0;j<all_times;j=j+1){
        Acc[j+1]=Acc[j]+P[j];
    }
    for(int j=0;j<20;j=j+1){
        cout << Acc[j] << " ";
    }
    cout << "\n" << flush;
    return 0;
}
