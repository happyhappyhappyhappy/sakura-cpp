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

int main(void){
    initial();
    int N=0; // N 参考書の数
    int M=0; // M アルゴリズム分野の数
    int X=0; // X マスターするのに必要な理解度
    cin >> N >> M >> X;

    debug("参考書数 %d \t アルゴリズム分野数 %d \t 必要理解度 %d \n",
    N,M,X);
    vector<int> COST(N,0); // COST 各参考書の値段
    vector<vector<int>> A(N,vector<int>(M,0)); // A 各参考書でUpする理解度数
    for(int j=0;j<N;j=j+1){
        cin >> COST[j];
        for(int k=0;k<M;k=k+1){
            cin >> A[j][k];
        }
    }
    // 入力確認
    int result=yamaMAX_INT;
    for(int j=0;j<N;j=j+1){
        debug("参考書 %d の 値段 %d\n",j,COST[j]);
    }
    for(int j=0;j<N;j=j+1){
        debug(" 参考書 %d の効果 → ",j);
        for(int k=0;k<M;k=k+1){
            debug(" %3d",A[j][k]);
        }
        debug("\n");
    }
    // 探索実行
    int START=(1<<N)-1;
    for(int j=START;0<j;j=j-1){
        vector<int> buyList; // 何を買うか→動的vector
        debug("%d : ",j);
        for(int k=0;k<N;k=k+1){
            int flagInt = j>>k;
            if(flagInt & 1){
                buyList.push_back(k);
            }
        }
        int getRef=(int)buyList.size();
        for(int k=0;k<getRef;k=k+1){
            debug(" %d",buyList[k]);
        }
        debug("\n");
        // 購入値段を知る
        int now_cost=0;
        for(int k=0;k<getRef;k=k+1){
            int pos=buyList[k];
            now_cost = now_cost+COST[pos];
        }
        debug("参考書 購入計 : %d\n",now_cost);
        // 理解度の和を求める
        vector<int> UD(M,0);
        for(int k=0;k<M;k=k+1){
            for(int m=0;m<getRef;m=m+1){
                int pos=buyList[m];
                UD[k]=UD[k]+A[pos][k];
            }
        }
        debug("理解度 : ");
        for(int k=0;k<M;k=k+1){
            debug(" %3d ",UD[k]);
        }
        debug("\n");
        bool udok=true;
        for(int k=0;k<M;k=k+1){
            if(UD[k] < X){
                udok=false;
                break;
            }
        }
        if(udok){
            debug("全分野を理解する事に成功した\n");
            if(now_cost < result ){
                result=now_cost;
            }
        }
    }
    if(result==yamaMAX_INT){
        result=-1;
    }
    cout << result << "\n" << flush;
    return 0;
}
