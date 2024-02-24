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
    vector<string> strs(N);
    vector<pair<int,int>> win(N);
    for(int j=0;j<N;j=j+1){
        cin >> strs[j];
    }
    for(int j=0;j<N;j=j+1){
        win[j]={count(strs[j].begin(),strs[j].end(),'o'),j+1};
    }
    // for(int j=0;j<N;j=j+1){
    //     debug("人 %d の 勝ち数 %d \n",win[j].second,win[j].first);
    // }
    auto cmp=[](pair<int,int> first,pair<int,int> second){
        if(first.first!=second.first){
            return first.first > second.first;
        }else{
            return first.second < second.second;
        }
    };
    sort(win.begin(),win.end(),cmp);
    // for(int j=0;j<N;j=j+1){
    //     debug("人 %d の勝ち数 %d\n",win[j].second,win[j].first);
    // }
    for(int j=0;j<N;j=j+1){
        if(j!=0){
            cout << " ";
        }
        cout << win[j].second;
    }
    cout << endl;
    return 0;
}
