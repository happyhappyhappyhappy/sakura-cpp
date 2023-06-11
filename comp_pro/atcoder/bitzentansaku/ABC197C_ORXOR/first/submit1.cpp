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
const int yamaMAX_INT = 1 << 30;
const ll yamaMAX_LL = 1LL << 60;
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
/***
void showTable(vector<vector<int>> &T){
    vector<int> L;
    for(int j=0;j<(int)T.size();j=j+1){
        L = T[j];
        for(int k=0;k<(int)L.size();k=k+1){
            debug(" %3d",L[k]);
        }
        debug("\n");
        L.clear();
    }
}
***/
int solver(int N,vector<int>& A){
    int res=yamaMAX_INT;
    int K=N-1; // 区切りの個数 sample1ならば 3-1->2で良い
    int PT = 1<<K;
    debug("総数 : %3d\n",PT);
    for(int j=0;j<(PT-1);j=j+1){
        // 入れ物準備
        vector<vector<int>> XORT;
        vector<int> ORL;
        ORL.push_back(A[0]);
        for(int k=0;k<K;k=k+1){
            int flug=(j>>k) & 1;
            if(flug == 1){// 2進数、1桁の1になったら 区切りを入れる
                ORL.push_back(A[k+1]);
            }
            else{
                XORT.push_back(ORL);
                ORL.clear();
                ORL.push_back(A[k+1]);
            }
        }
        XORT.push_back(ORL);
        ORL.clear();
        // showTable(XORT);
        // まず一列ずつORを求める
        int orv;
        vector<int> xorl;
        for(int k=0;k<(int)XORT.size();k=k+1){
            ORL=XORT[k];
            orv=ORL[0];
            for(int m=1;m<(int)ORL.size();m=m+1){
                orv=orv | ORL[m];
            }
            xorl.push_back(orv);
            ORL.clear();
        }
        XORT.clear();
        int XOR_RESULT=xorl[0];// まとめる
        for(int k=1;k<(int)xorl.size();k=k+1){
            XOR_RESULT=XOR_RESULT^xorl[k];
        }
        chmin(res,XOR_RESULT);
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
