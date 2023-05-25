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

int solver(string &M){
    int res = yamaMAX_INT;
    int strlen=M.size();
    int patMax=(1<<strlen)-1;
    for(int j=0;j<patMax;j=j+1){
        int all_sum=0;
        int res_check=0;
        vector<bool>  remainFlug(strlen,true);
        for(int k=0;k<strlen;k=k+1){
            int bitC=((j >> k) & 1 );
            if(bitC){
                remainFlug[k]=false;
            }
        }
        for(int k=0;k<strlen;k=k+1){
            if(remainFlug[k]){
                all_sum=all_sum+(M.at(k)-'0');
            }
        }
        for(int k=0;k<strlen;k=k+1){
            if(remainFlug[k]==false){
                res_check=res_check+1;
            }
        }
        if(all_sum%3==0){
            if(res_check<res)
                {
                    res=res_check;
                }
            }
    }
    if(res == yamaMAX_INT){
        res=-1;
    }
    return res;
}

int main(void){
    initial();
    string M;
    cin >> M;
    cout << solver(M) << "\n" << flush;
    return 0;
}
