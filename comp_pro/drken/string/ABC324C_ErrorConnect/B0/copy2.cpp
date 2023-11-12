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
    int N;
    string T;
    cin >> N >> T;
    vector<string> AS(N);
    for(int j=0;j<N;j=j+1){
        cin >> AS[j];
    }
    vector<int> res;
    for(int j=0;j<N;j=j+1){
        const auto &S = AS[j];
        int ssize = (int)S.size();
        int tsize = (int)T.size();
        if(2 <= abs(ssize-tsize)){
            continue;
        }
        int pre=0;
        int suf=0;
        for(pre = 0;pre <min(ssize,tsize);pre=pre+1){
            if(S[pre]!=T[pre]){
                break;
            }
        }
        for(suf=0;suf<min(ssize,tsize);suf=suf+1){
            if(S[ssize-1-suf]!=T[tsize-1-suf]){
                break;
            }
        }
        char* sc = const_cast<char*>(S.c_str());
        char* tc = const_cast<char*>(T.c_str());
        debug("S = %s,T = %s => pre = %d,suf = %d\n",sc,tc,pre,suf);
        if(min(ssize,tsize) <= (pre+suf)){
            debug("この場合先頭一致数と後ろ一致数の和 小さいサイズと比べて大きい->削・足すれば良い\n");
            res.push_back(j+1);
        }else if((ssize == tsize) && pre+suf+1==ssize){
            debug("この場合先頭一致数と後ろ一致数の和+1がSのサイズと比べて同じ->修正すれば良い\n");
            res.push_back(j+1);
        }else{
            debug("この場合どうしようもない\n");

        }
    }
    cout << (int)res.size() << "\n" << flush;
    for(auto v:res){
        cout << v << " ";
    }
    cout << "\n" << flush;
    return 0;
}
