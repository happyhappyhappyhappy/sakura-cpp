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
pair<int,int> solver(int K,int G,int M){
    pair<int,int> ans;
    debug("K=%d,G=%d,M=%d\n",K,G,M);
    int g=0;
    int m=0;
    int cnt=0;
    while(true){
            if(g==G){
                g=0;
                // debug("%d 回目は グラスを空にした\n",cnt+1);
                // debug("%d 回目 : グラスは %d(of %d),マグは %d(of %d)\n",cnt+1,g,G,m,M);
            }else{
                if(m==0){
                    m=M;
                    // debug("%d 回目は マグを満タンにした\n",cnt+1);
                    // debug("%d 回目 : グラスは %d(of %d),マグは %d(of %d)\n",cnt+1,g,G,m,M);
                }else{
                    if((G-g)<m){
                        // debug("%d 回目は マグから %d グラスに移動し グラスを満タンにした\n",cnt+1,G-g);
                        m=m-(G-g);
                        g=G;
                        // debug("%d 回目 : グラスは %d(of %d),マグは %d(of %d)\n",cnt+1,g,G,m,M);
                    }else{
                        // debug("%d 回目は マグから %d グラスに移動しグラスを %d(of %d) マグを空にした\n",cnt+1,m,m+g,G);
                        g=g+m;
                        m=0;
                        // debug("%d 回目 : グラスは %d(of %d),マグは %d(of %d)\n",cnt+1,g,G,m,M);
                    }
                }
            }
            cnt=cnt+1;
            if(cnt==K){
                break;
            }
        }
    ans=make_pair(g,m);
    return ans;
}
int main(void){
    initial();
    int G,M,K;
    cin >> K >> G >> M;
    pair<int,int> ans;
    ans=solver(K,G,M);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}
