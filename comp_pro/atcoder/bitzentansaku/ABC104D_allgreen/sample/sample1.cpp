#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
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

int D;
ll G;
vector<ll> p;
vector<ll> c;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    cin >> D >> G;
    p.resize(D);
    c.resize(D);
    for(int j=0;j<D;j=j+1){
        cin >> p[j] >> c[j];
    }
    ll res = 1<<29;
    for(int bit=0;bit<(1<<D);bit=bit+1){
        debug("bit = %d の場合\n",bit);
        ll sum=0;
        ll num=0;
        for(int j=0;j<D;j=j+1){
            if(bit & (1<<j)){
                debug("%d 個目が全部解けたとしている\n",j);
                sum = sum+c[j]+p[j]*100*(j+1);
                debug("合計 %lld 点\n",sum);
                num = num+p[j];
                debug("解いた数 %lld 個\n",num);
            }
            if(G <= sum){
                debug("合計点突破 %lld点 解いた問題数を %lld 個とセットしてみる\n",sum,num);
                res = min(res,num);
            }
            else{
                debug("解けなかったので貪欲法へ飛ぶ\n"); // TODO 2023-06-20 19:42:24
                for(int j=D-1;0<=j;j=j-1){
                    if(bit & (1<<j)){
                        continue;
                    }
                    for(int k=0;k<p[j];k=k+1){
                        if(G <= sum){
                            break;
                        }
                        sum = sum + 100*(j+1);
                        num=num+1;
                    }
                }
                res = min(res,num);
            }
        }
    }
    cout << res << "\n" << flush;
    return 0;
}
