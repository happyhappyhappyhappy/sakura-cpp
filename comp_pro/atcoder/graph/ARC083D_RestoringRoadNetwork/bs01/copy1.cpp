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
const int INF=INT_MAX/2;
vector<vector<int>> A(303,vector<int>(303,INF));
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> N;
    for(int j=0;j<N;j=j+1){
        for(int k=0;k<N;k=k+1){
            cin >> A[j][k];
        }
    }
    vector<pair<ll,pair<int,int>>> v;
    for(int j=0;j<N;j=j+1){
        for(int k=j+1;k<N;k=k+1){
            v.push_back({-A[j][k],{j,k}});
        }
    }
    debug("---sort前---\n");
    for(auto& p:v){
        debug("%d -> %d の距離は %lld\n",p.second.first,p.second.second,p.first);
    }
    sort(v.begin(),v.end());
    debug("---sort後---\n");
    for(auto& p:v){
        debug("%d -> %d の距離は %lld\n",p.second.first,p.second.second,p.first);
    }
    // for(auto& e:v){
    //     ll c = e.first;
    //     int a = e.second.first;
    //     int b = e.second.second;
    //     debug("%d -> %d の 距離は %lld です\n",a,b,c);
    // }
    return 0;
}
