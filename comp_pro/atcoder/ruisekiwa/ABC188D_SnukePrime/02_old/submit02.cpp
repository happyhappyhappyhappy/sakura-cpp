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
struct plan{
    long long start;
    long long end;
    long long price;
};

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N;
    cin >> N;
    vector<plan> tasks(N);
    for(int j=0;j<N;j=j+1){
        cin >> tasks[j].start >> tasks[j].end >> tasks[j].price;
    }
    vector<long long> dates_org;
    dates_org.push_back(1);
    for(int j=0;j<N;j=j+1){
        dates_org.push_back(tasks[j].start);
        dates_org.push_back(tasks[j].end+1);
    }
    vector<long long> dates=dates_org;
    sort(dates.begin(),dates.end());
    dates.erase(unique(dates.begin(),dates.end()),dates.end());
    for(auto& e:dates){
        debug("%lld ",e);
    }
    debug("\n");
    return 0;
}
