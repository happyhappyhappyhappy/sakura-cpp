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
bool checker(string& key){
    const string base="ABCDEAEDCBA";
    if(base.find(key) != std::string::npos){
        return true;
    }
    else{
        return false;
    }
}
bool solver(string& s,string& t){
    if(checker(s) == checker(t)){
        return true;
    }else{
        return false;
    }

}
int main(void){
    initial();
    string S,T;
    cin >> S >> T;
    // const char* Sc=S.c_str();
    // const char* Tc=T.c_str();
    // debug("Sは %s , Tは %s\n",Sc,Tc);
    if(solver(S,T)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
