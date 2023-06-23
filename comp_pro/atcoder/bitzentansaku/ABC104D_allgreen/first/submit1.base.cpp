#include<bits/stdc++.h>
// 2023-06-23 17:24:12 元解答を借りたのみなのでもう一度
// 始めから書いてみる
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
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
ll G;
vector<ll> bs; // 各問題の数
vector<ll> cs; // コンプリートスコア

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
ll solver(int D,ll G){
    ll res=0;
    for(int j=0;j<D;j=j+1){
        res=res+bs[j];
    }
    for(ll bit=0;bit<(1<<D);bit=bit+1){
        string bitChain="";
        for(int j=0;j<D;j=j+1){
            if((bit>>j) & 1){
                bitChain.append("1");
            }
            else{
                bitChain.append("0");
            }
        }
        debug("検索フラグコード -- %s --\n",bitChain.c_str());
        ll sum=0;
        ll count=0;
        for(int j=0;j<D;j=j+1){
            if(((bit>>j) & 1)==1){
                int j1=j+1;
                debug("%3d 問目を全部解いた物とできる。\n",j1);
                sum=sum+cs[j]+bs[j]*(j1*100);
                count = count+bs[j];
            }
        }
        if(G <= sum){
            debug("合計 %lldになり条件 %lldを満たしました。最小値を%lldと比較します\n",
            sum,G,count);
            chmin(res,count);
        }
        else{
            debug("合計が%lldだけだったので貪欲法に入ります\n",sum);
            for(int j=D-1;0<=j;j=j-1){
                int j1=j+1;
                if(((bit>>j)&1)==1){
                    debug("%d 問目は回答済みなのでスキップします\n",j1);
                    continue;
                }
                for(int k=0;k<bs[j];k=k+1){
                    if(G <= sum){
                        debug("ここで合計が %lld と 条件 %lld を超えましたので貪欲法ループを抜けます。これまでの問題数 %lld を最終結果とします\n",
                        sum,G,count);
                        break;
                    }
                    debug("%d の %d テストがOKになりました\n",j1,k);
                    sum = sum+100*j1;
                    count = count+1;
                }
            }
            debug("最終的には 合計 %lldにて %lldを超えていると思いますの最低数 %lld を %lldと比較します\n",
            sum,G,count,res);
            chmin(res,count);
        }
    }
    return res;
}
int main(void){
    initial();
    int N=0;
    ll C=0;
    cin >> N >> C;
    bs.resize(N);
    cs.resize(N);
    for(int j=0;j<N;j=j+1){
        cin >> bs[j] >> cs[j];
    }
    cout << solver(N,C) << "\n" << flush;
    return 0;
}
