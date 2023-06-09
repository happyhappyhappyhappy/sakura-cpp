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
const ll yamaMAX_LL = 1LL << 60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
string mtobinary(int N){
    string res= "";
    while(N!=0){
        if((N%2)==1){
            res=res+"1";
        }
        else{
            res=res+"0";
        }
        N = N / 2;
    }
    return res;
}
int solver(int N,vector<int>& A){
    int res=yamaMAX_INT;
    int K=N-1; // 区切りの個数 sample1ならば 3-1->2で良い
    int PT = 1<<K;
    for(int j=1;j<PT;j=j+1){
        // vector<vector<int>> xorbox;
    debug("j= %d の場合\n",j);
    // TODO: python版分かるまで見直し
    //2023-06-09 18:52:43
    debug("0->");
        for(int k=1;k<K;k=k+1){
            bool flug=j>>k;
            if(flug){// 2進数、1桁の1になったら 区切りを入れる
                debug("\n%d->",k);
            }
            else{
                debug("%d->",k);
            }
        }
        debug("%d\n",K);
    }
    return res;
}
int main(void){
    initial();
    int N=0;
    cin >> N;
    vector<int> A(N,0);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    cout << solver(N,A) << "\n" << flush;
    return 0;
}
