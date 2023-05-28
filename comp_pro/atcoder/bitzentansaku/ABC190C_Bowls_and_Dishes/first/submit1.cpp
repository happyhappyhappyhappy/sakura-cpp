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
int solver(int N,int M,int K,vector<vector<int>> &C,vector<vector<int>> &INB){
    int answer=0;
    for(int selpos=0;selpos<(1<<K);selpos=selpos+1){
        vector<int> bitChain(K,0);
        int ok_count=0;
        for(int bit=0;bit<K;bit=bit+1){
            int movebit=selpos >> bit;
            if(movebit & 1){
                bitChain[bit]=1;
            }
        }
        // 皿そのものを用意する
        vector<int> D(N+1,0);
        for(int bit=0;bit<K;bit=bit+1){
            int selectDish = INB[bit][bitChain[bit]];
            D[selectDish]=D[selectDish]+1;
        }
        // 条件確認
        for(int j=0;j<M;j=j+1){
            int cdFirst = C[j][0];
            int cdSecond = C[j][1];
            if( 0 < D[cdFirst] && 0 < D[cdSecond]){
                ok_count=ok_count+1;
            }
        }
        if(answer < ok_count){
            answer = ok_count;
        }
    }
    return answer;
}
int main(void){
    initial();
    int N=0;
    int M=0;
    int K=0;
    cin >> N >> M;
    vector<vector<int>> C(M,vector<int>(2,0));
    for(int j=0;j<M;j=j+1){
        cin >> C[j][0] >> C[j][1];
    }
    vector<int> BOX(N+1,0);
    cin >> K;
    vector<vector<int>> INB(K,vector<int>(2,0));
    for(int j=0;j<K;j=j+1){
        cin >> INB[j][0] >> INB[j][1];
    }
    cout << solver(N,M,K,C,INB) << "\n" << flush;
    return 0;
}
