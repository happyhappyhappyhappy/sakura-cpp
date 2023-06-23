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
        string bitChain;
        for(int j=0;j<D;j=j+1){
            int bitChkNum=1<<j;
            debug("...%d とbit照合.",bitChkNum);
            if(bit & (1<<j)){
                bitChain.append("1");
            }
            else{
                bitChain.append("0");
            }
        }
        ll sum=0;
        ll num=0;
        debug("\n---- 探索チェーン %s ----\n",bitChain.c_str());
        for(int j=0;j<D;j=j+1){
            debug("各点の処理前 %lld 点 想定は 0 点 \n",sum);
            if(bit & (1<<j)){
                debug("%d 個目が全部解けたとしている\n",j);
                sum = sum+c[j]+p[j]*100*(j+1);
                debug("合計 %lld 点\n",sum);
                num = num+p[j];
                debug("解いた数 %lld 個\n",num);
            }
            debug("処理後の合計 %lld 点\n",sum);
            if(G <= sum){
                debug("%u:現在の点数 %3lld 点で、合計点突破 解いた問題数を %lld 個とセットしてみる\n",__LINE__,sum,num);
                res = min(res,num);
            }
            else{
                debug("解けなかったので貪欲法へ飛ぶ\n");
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
                debug("%u: 最終合計 %lld で限界 %lld を突破していた\n",
                __LINE__,sum,G);
                res = min(res,num);
            }
        }
    }
    cout << res << "\n" << flush;
    return 0;
}
