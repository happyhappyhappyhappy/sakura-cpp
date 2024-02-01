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
    int N,S,M,L;
    cin >> N >> S >> M >> L;
    int ans=yamaMAX_INT;
    for(int s=0;s<=100;s=s+1){
        for(int m=0;m<=100;m=m+1){
            for(int l=0;l<=100;l=l+1){
                int count=s*6+m*8+l*12;
                if(N <= count){
                    int cost= S*s+M*m+L*l;
                    if(cost < ans){
                        ans=cost;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
