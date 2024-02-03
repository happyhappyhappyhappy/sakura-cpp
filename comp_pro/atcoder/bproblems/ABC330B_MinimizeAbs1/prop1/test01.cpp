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
    int A,L,R,X;
    cin >> A >> L >> R;
    X = L;
    for(int Xa=L;Xa<R+1;Xa=Xa+1){
        bool flug=true;
        for(int Y=L;Y<R+1;Y=Y+1){
            if(abs(Xa-A) > abs(Y-A)){
                debug("NG:abs(%d(Xa)-%d(A)) > abs(%d(Y)-%d(A))\n",Xa,A,Y,A);
                flug=false;
                break;
            }else{
                debug("OK:abs(%d(Xa)-%d(A)) <= abs(%d(Y)-%d(A))\n",Xa,A,Y,A);
            }
        }
        if(flug){
            debug("%dはXとしてもOK\n",Xa);
            X = Xa;
        }else{
            debug("%dはXには出来ない\n",Xa);
        }
    }
    cout << X << endl;
    return 0;
}
