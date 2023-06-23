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
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
// 大域変数
int D; // 問題数
ll G; // 目標点

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
string bitCode(int B){
    string res="";
    for(int j=0;j<D;j=j+1){
        if(((B>>j)&1)==1){
            res=res+"1";
        }
        else{
            res=res+"0";
        }
    }
    return res;
}
ll solver(vector<ll> &tc,vector<ll> &tp,vector<ll> &cp){
    ll res=0;
    for(int j=0;j<D;j=j+1){
        res=res+tc[j];
    }
    for(int bit=0;bit<(1<<D);bit=bit+1){
        string bc=bitCode(bit);
        ll sum=0; // 得点合計
        ll count=0; // テスト合計数
        debug("----- 回答完了コード : %s -----\n",bc.c_str());
        for(int j=0;j<D;j=j+1){
            int j1=j+1;
            int bitFlg=(bit>>j)&1;
            if(bitFlg==1){
                debug("%3d 問目をコンプリートしました\n",j1);
                sum=sum+tp[j]*tc[j]+cp[j];
                count=count+tc[j];
                debug("現在の得点 %3lld 完了テスト数 %3lld\n",
                sum,count);
            }else{
                debug("%3d 問目は未着手\n",j1);
            }
        } // 指定問題の解答完了
        if(G <= sum){
            debug("bit指定問題だけで条件をみたしました(%lld/%lld)。この値を渡します。\n",
            sum,G);
            chmin(res,count);
        }
        else{
            debug("bit指定の問題では条件を満たせませんでした(%lld/%lld)。高ポイントのものから貪欲法に入ります。\n",
            sum,G);
            debug("これから開発\n");
            for(int j=D-1;0<=j;j=j-1){
                int j1=j+1;
                int bitFlg=(bit>>j)&1;
                if(bitFlg==1){
                    debug("%d 問目はコンプリート済みですよね。スキップします\n",j1);
                    continue;
                }
                else{
                    // TODO: j番目を一テストずつ解いていく
                    // 変数はkを利用
                    // 2023-06-23 19:29:54
                }
            }
        }
    }
    return res;
}
int main(void){
    initial();
    cin >> D >> G;
    vector<ll> TC(D);
    vector<ll> CP(D);
    vector<ll> TP(D);
    for(int j=0;j<D;j=j+1){
        TP[j]=100*(j+1);
        cin >> TC[j] >> CP[j];
    }
    cout << solver(TC,TP,CP) << "\n" << flush;
    return 0;
}
