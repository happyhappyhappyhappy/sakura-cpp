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
// const int yamaMAX_INT = 1 << 29; <- 今回はIntが使える範囲ギリギリまで増やすのでこれは無し

const ll yamaMAX_LL = 1LL << 60;
int N;
int yamaMAX_INT;
vector<vector<int>> XORL;
vector<int> A;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    yamaMAX_INT=(1<<30)+1;
}
// TODO: 具体的な数値も入れてわかりやすく2023-07-04 19:39:04
string bit2str(int X,int BASE){
    string res="";
    for(int bit=0;bit<BASE;bit=bit+1){
        int flag=(X >> bit)&1;
        if(flag==1){
            res=res+'|';
        }else{
            res=res+'-';
        }
    }
    return res;
}
int solver(void){
    int result=0;
    int fwc=N-1;
    for(int bit=0;bit<(1<<fwc);bit=bit+1){
        string fw;
        fw = bit2str(bit,fwc);
        debug("%d -> %s\n",bit,fw.c_str());
    }
    return result;
}
int main(void){
    initial();
    cin >> N;
    A.resize(N);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    cout << solver() << "\n" << flush;
    // cout << yamaMAX_INT << "\n" << flush;
    return 0;
}
