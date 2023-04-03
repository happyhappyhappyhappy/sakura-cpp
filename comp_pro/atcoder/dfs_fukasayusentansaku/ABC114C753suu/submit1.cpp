#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
using num753=tuple<ll,bool,bool,bool>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll solver(ll N){
    ll answer=0;
    num753 first=make_tuple(0,false,false,false);
    stack<num753> S;
    S.push(first);
    while(S.empty()==false){
        num753 nowSet=S.top();
        S.pop();
        ll num=get<0>(nowSet);
        bool has3=get<1>(nowSet);
        bool has5=get<2>(nowSet);
        bool has7=get<3>(nowSet);
        if(N < num){
            continue;
        }
        if ((has3 && has5 && has7)==true){
            debugt(num);
            answer = answer+1;
        }
        vector<num753> T(3);
        T[0]=make_tuple(num*10+3,true,has5,has7);
        T[1]=make_tuple(num*10+5,has3,true,has7);
        T[2]=make_tuple(num*10+7,has3,has5,true);
        for(int j=0;j<3;j=j+1){
            S.push(T[j]);
        }
    }


    return answer;
}

int main(void){
    initial();
    ll N;
    cin >> N;
    cout << solver(N) << "\n" << flush;
    return 0;
}

