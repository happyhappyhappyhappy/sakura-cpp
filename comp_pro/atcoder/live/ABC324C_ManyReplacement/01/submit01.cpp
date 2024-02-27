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
    string fromstr="abcdefghijklmnopqrstuvwxyz"s;
    string tostr="abcdefghijklmnopqrstuvwxyz"s;
    int N,Q;
    string S;
    cin >> N;
    cin >> S;
    cin >> Q;
    for(int j=0;j<Q;j=j+1){
        char c,d;
        cin >> c >> d;
        for(auto &&e:tostr){
            if(e==c){
                e=d;
            }
        }
    }
    // cout << tostr << endl;
    for(int j=0;j<N;j=j+1){
        char nowC = S[j];
        for(int k=0;k<26;k=k+1){
            if(fromstr[k]==nowC){
                cout << tostr[k];
            }
        }
    }
    cout << "\n" << flush;
    return 0;
}
