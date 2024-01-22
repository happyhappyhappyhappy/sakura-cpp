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
void uniqueSort(vector<long long> &res){
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
}
long long solver(vector<plan>& P,long long& C,vector<long long>& dates){
    long long ans=0;
    int dbcnt=(int)dates.size();
    int N=(int)P.size();
    vector<long long> acc(dbcnt,0);
    // いもす法適用
    for(int j=0;j<N;j=j+1){
        long long st=P[j].start;
        long long en=P[j].end+1;
        int stpos=lower_bound(dates.begin(),dates.end(),st)-dates.begin();
        int enpos=lower_bound(dates.begin(),dates.end(),en)-dates.begin();
        acc[stpos]=acc[stpos]+P[j].price;
        acc[enpos]=acc[enpos]-P[j].price;
    }
    // 累積和
    for(int j=1;j<dbcnt;j=j+1){
        acc[j]=acc[j]+acc[j-1];
    }
    for(int j=0;j<dbcnt-1;j=j+1){
        ans = ans + min(acc[j],C)*(dates[j+1]-dates[j]);
    }
    return ans;
}
int main(void){
    initial();
    int N;
    long long C;
    cin >> N >> C;
    vector<plan> P(N);
    vector<long long> date_org;
    for(int j=0;j<N;j=j+1){
        cin >> P[j].start >> P[j].end >> P[j].price;
        date_org.push_back(P[j].start);
        date_org.push_back(P[j].end+1);
    }
    date_org.push_back(1);
    vector<long long> dates=date_org;
    uniqueSort(dates);
    long long ans=solver(P,C,dates);
    cout << ans << "\n" << flush;
    return 0;
}
