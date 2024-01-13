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
    long long N,C;
    cin >> N >> C;
    vector<pair<long long,long long>> event;
    for(ll i=0;i<N;i=i+1){
        ll a,b,c;
        cin >> a >> b >> c;
        event.emplace_back(a-1,c);
        event.emplace_back(b,-c);
    }
    sort(event.begin(),event.end());
    for(auto& e:event){
        cout << e.first << " " << e.second << "\n" << flush;
    }
    long long ans=0,fee=0,t=0;
    for(auto [x,y]:event){
        if(x != t){
            cout << "ただいま " << t << " 日を計算しています\n" << flush;
            ans=ans+min(C,fee)*(x-t);
            cout << min(C,fee) << " 円を " << (x-t) << " 日 追加利用します\n" << flush;
            cout << t << " 日を " << x << " 日に 治します\n" << flush;
            t = x;
        }
        cout << fee << " 円 に " << y << " 円追加します \n" << flush;
        fee=fee+y;
    }
    return 0;
}
