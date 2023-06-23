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

void showVector1(vector<int> &X){
    int S=X.size();
    for(int j=0;j<S;j=j+1){
        debug(" %d ",X[j]);
    }
    debug("\n\n");
}
void showVector2(vector<vector<int>> &G){
    int H=G.size();
    int W=G[0].size();
    for(int j=0;j<H;j=j+1){
        for(int k=0;k<W;k=k+1){
            debug(" %2d",G[j][k]);
        }
        debug("\n");
    }
    debug("\n\n");
}

int main(void){
    initial();
    int N=0;
    int M=0;
    int X=0;
    cin >> N >> M >> X;
    vector<vector<int>> G(N,vector<int>(M,0));
    vector<int> book(N,0);
    for(int j=0;j<N;j=j+1){
        cin >> book[j];
        for(int k=0;k<M;k=k+1){
            cin >> G[j][k];
        }
    }
    int minCost=yamaMAX_INT;
    showVector1(book);
    showVector2(G);
    for(int j=((1<<N)-1);j>0;j=j-1){
        vector<int> buyList;
        int nowSum = 0;
        vector<int> skillSum(M,0);
        for(int k=0;k<N;k=k+1){
            int F=j>>k;
//            debug("F=%d\n",F);
            if((F & 1) == 1){
                buyList.push_back(k);
            }
        }
        debug("%4d : ",j);
        for(int k=0;k<(int)buyList.size();k=k+1){
            int selectBook = buyList[k];
            nowSum=nowSum+book[selectBook];
            for(int m=0;m<M;m=m+1){
                skillSum[m]=skillSum[m]+G[selectBook][m];
            }
            // debug(" %2d",buyList[k]);
        }
        debug(" %d :",nowSum);
        for(int m=0;m<M;m=m+1){
            debug(" %d ",skillSum[m]);
        }
        bool okflug = true;
        for(int m=0;m<M;m=m+1){
            if(skillSum[m] < X){
                okflug=false;
            }
        }
        if(okflug){
            debug(":OK ");
            if(nowSum < minCost){
                minCost = nowSum;
            }
        }
        else{
            debug(":NG ");
        }
        debug("\n");
    }
    if(minCost == yamaMAX_INT){
        minCost = -1;
    }
    cout << minCost << "\n" << flush;
    return 0;
}
