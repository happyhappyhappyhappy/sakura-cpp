#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/lib/dump.hpp"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
// #define to_string(...) 42
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
    vector<int> M(N,0);
    for(auto& e:M){
        cin >> e;
    }
    int res=0;
    for(int j=1;j<N+1;j=j+1){
        for(int k=1;k<M[j-1]+1;k=k+1){
            string str=std::to_string(j)+std::to_string(k);
            unordered_set<char> S;
            // cout << str << "->";
            for(int m=0;m<(int)str.size();m=m+1){
                S.insert(str.at(m));
            }
            if((int)S.size()==1){
                // debug("%d 月 %d 日はぞろ目です\n",j,k);
                res=res+1;
            }
            // cout << S.size() << endl;
        }
    }
    cout << res << endl;
    return 0;
}
