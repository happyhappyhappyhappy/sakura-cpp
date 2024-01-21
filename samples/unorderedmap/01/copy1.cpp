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
    unordered_map<string,int> myMap;
    myMap["Alice"]=25;
    myMap["Bob"]=30;
    myMap["Charlie"]=22;
    cout << "Bob -> " << myMap["Bob"] << "\n" << flush;
    for(auto& e:myMap){
        cout << e.first << " は " << e.second << "\n" << flush;
    }
    return 0;
}
