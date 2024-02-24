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
    int N;
    cin >> N;
    vector<pair<int,int>> win(N);
    for(int j=0;j<N;j=j+1){
        string S;
        cin >> S;
        win[j]={count(S.begin(),S.end(),'o'),j};
    }
    for(int j=0;j<N;j=j+1){
        pair<int,int> res=win[j];
        debug("(%d,%d)\n",res.first,res.second);
    }
    auto cmp = [](pair<int,int> a,pair<int,int> b){
        if(a.first!=b.first){
            return b.first < a.first;
        }else{
            return a.second < b.second;
        }
    };
    sort(win.begin(),win.end(),cmp);
    for(int j=0;j<N;j=j+1){
        debug("(%d,%d)\n",win[j].first,win[j].second);
    }
    return 0;
}
