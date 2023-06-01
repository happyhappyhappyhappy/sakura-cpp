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
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int solver(string str){
    int res=0;
    int strcount=(int)str.size();
    map<string,int> M;
    for(int j=0;j<strcount-1;j=j+1){
        string twochar=string{str[j],str[j+1]};
        M[twochar]=M[twochar]+1;
        debug("%3d -> %s\n",j,twochar.c_str());
    }
    res=M.size();
    return res;
}
int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    while(testcase--){
        int c_cnt;
        string melod;
        cin >> c_cnt;
        cin >> melod;
        // debug("%3d -> %s\n",c_cnt,melod.c_str());
        cout << solver(melod) << "\n" << flush;
    }
    return 0;
}
