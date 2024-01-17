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
struct Plan{
    long long start_d;
    long long end_d;
    long long price;
};
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> N >> C;
    vector<Plan> task(N);
    for(int j=0;j<N;j=j+1){
        cin >> task[j].start_d >> task[j].end_d >> task[j].price;
    }
    vector<long long> date_org;
    date_org.push_back(0); // 基準時間を入れる
    for(int j=0;j<N;j=j+1){
        date_org.push_back(task[j].start_d);
        date_org.push_back(task[j].end_d+1);
    }
    vector<long long> datedb=date_org;
    sort(datedb.begin(),datedb.end());
    datedb.erase(unique(datedb.begin(),datedb.end()),datedb.end());
    int dbsize=(int)datedb.size();
    vector<long long> acc(dbsize,0);
    // いもす情報セット
    for(int j=0;j<N;j=j+1){
        long long pri=task[j].price;
        int st=lower_bound(datedb.begin(),datedb.end(),task[j].start_d)-datedb.begin();
        int en=lower_bound(datedb.begin(),datedb.end(),task[j].end_d+1)-datedb.begin();
        acc[st]=acc[st]+pri;
        acc[en]=acc[en]-pri;
    }
    // 累積和
    for(int j=0;j<dbsize-1;j=j+1){
        acc[j+1]=acc[j+1]+acc[j];
    }
    // mes="累積和の結果です";
    long long ans=0;
    for(int j=0;j<dbsize;j=j+1){
        ans=ans+min(C,acc[j])*(datedb[j+1]-datedb[j]);
    }
    cout << ans << "\n" << flush;
    return 0;
}
