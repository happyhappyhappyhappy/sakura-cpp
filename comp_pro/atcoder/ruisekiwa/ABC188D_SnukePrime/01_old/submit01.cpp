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
int N;
long long C;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> N >> C;
    vector<long long> F(N);
    vector<long long> T(N);
    vector<long long> c(N);
    for(int j=0;j<N;j=j+1){
        cin >> F[j] >> T[j] >> c[j];
    }
    // for(int j=0;j<N;j=j+1){
    //     debug("%lld から %lld まで 費用 %lld。\n",F[j],T[j],c[j]);
    // }
    vector<long long> dates_org;
    for(auto& e:F){
        dates_org.push_back(e);
    }
    for(auto& e:T){
        dates_org.push_back(e+1);
    }
    vector<long long> dates_db=dates_org;
    dates_db.erase(unique(dates_db.begin(),dates_db.end()),dates_db.end());
    sort(dates_db.begin(),dates_db.end());
    for(int j=0;j<(int)dates_db.size();j=j+1){
        debug("dates_db[%d]->%lld\n",j,dates_db[j]);
    }
    int d=(int)dates_db.size();
    vector<long long> acc(d+1,0);
    for(int j=0;j<N;j=j+1){
        int f=lower_bound(dates_db.begin(),dates_db.end(),F[j])-dates_db.begin();
        int t=lower_bound(dates_db.begin(),dates_db.end(),T[j]+1)-dates_db.begin();
        debug("%d 日目 位置 %d に %lld を足し込み 位置 %d に %lld を引く\n",j,f,c[j],t,c[j]);
        acc[f]=acc[f]+c[j];
        acc[t]=acc[t]-c[j];
    }
    for(int j=0;j<d;j=j+1){
        acc[j+1]=acc[j+1]+acc[j];
    }
    debug("累積和結果\n");
    for(int j=0;j<d+1;j=j+1){
        debug("%d は %lld\n",j,acc[j]);
    }
    debug("%d day -> %lld\n",d,dates_db[d]);
    ll ans=0;
    for(int j=0;j<d;j=j+1){
        ans=ans+min(C,acc[j])*(dates_db[j+1]-dates_db[j]);
        debug("%d\n",__LINE__);
    }
    cout << ans << "\n" << flush;
    return 0;

}
