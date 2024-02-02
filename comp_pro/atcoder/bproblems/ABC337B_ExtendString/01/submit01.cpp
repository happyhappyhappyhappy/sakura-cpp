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
string solver(string& S){
    string str = "OK";
    // const char* x=S.c_str();
    int acount = (int)std::count(S.begin(),S.end(),'A');
    int bcount = (int)std::count(S.begin(),S.end(),'B');
    int ccount = (int)std::count(S.begin(),S.end(),'C');
    string mS=string(acount,'A')+string(bcount,'B')+string(ccount,'C');
    // cout << mS << endl;
    // debug("String: %s\n",x);
    if(S==mS){
        str="Yes";
    }else{
        str="No";
    }
    return str;
}
int main(void){
    initial();
    string S;
    cin >> S;
    string ans = solver(S);
    cout << ans << endl;
    return 0;
}
