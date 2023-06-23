#include<bits/stdc++.h>
#include<stack>
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
const ll yamaMAX_LL = 1LL << 58;
const ll resultMAX=4000000000;

vector<ll> lunlun;

void lunlun_make(ll seed){
    stack<ll> ST;
    ST.push(seed);
    while(ST.empty()==false){
        ll nowNum = ST.top();// 取り出しにはtop
        ST.pop();// 削除はpop
        if(nowNum > resultMAX){
            continue;
        }
        lunlun.push_back(nowNum);
        ll unitsPlace=nowNum%10;
        // 一の位弄らない
        ST.push(nowNum*10+unitsPlace);
        // 一の位一つ加える
        if(unitsPlace != 9){
            ST.push(nowNum*10+unitsPlace+1);
        }
        // 一の位一つ引く
        if(unitsPlace !=0){
            ST.push(nowNum*10+unitsPlace-1);
        }
    }
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(ll j=1;j<=9;j=j+1){
        lunlun_make(j);
    }
    sort(lunlun.begin(),lunlun.end());
}

int main(void){
    initial();
    int Q;
    cin >> Q;
    cout << lunlun[Q-1] << "\n" << flush;
    return 0;
}
