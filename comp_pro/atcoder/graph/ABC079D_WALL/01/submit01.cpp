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
const int INF=1000000000;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void printV(const vector<vector<int>>& X,string titleStr){
    const char* p=titleStr.c_str();
    debug("----%s-----\n",p);
    int H=(int)X.size();
    int W=(int)X[0].size();
    for(int j=0;j<H;j=j+1){
        for(int k=0;k<W;k=k+1){
            debug("%3d",X[j][k]);
            if(k == W-1){
                debug("\n");
            }else{
                debug(" ");
            }
        }
    }
}
void floydWarshall(vector<vector<int>> &A,int V){
    for(int p=0;p<V;p=p+1){
        for(int j=0;j<V;j=j+1){
            for(int k=0;k<V;k=k+1){
                if(A[j][p] < INF && A[p][k] < INF){
                    int x = A[j][p]+A[p][k];
                    if(x < A[j][k]){
                        debug("%d -> %d を %d 寄り道ルートにする\n",j,k,p);
                        A[j][k]=x;
                    }
                }
            }
        }
    }
}
int main(void){
    initial();
    int H , W;
    cin >> H >> W;
    vector<vector<int>> A(10,vector<int>(10,INF));
    vector<vector<int>> Wall(H,vector<int>(W,-1));
    for(int j=0;j<10;j=j+1){
        for(auto& e:A[j]){
            cin >> e;
        }
    }
    for(int j=0;j<H;j=j+1){
        for(auto& e:Wall[j]){
            cin >> e;
        }
    }

//    printV(A,string("魔法コスト"));
//    printV(Wall,string("壁"));
    floydWarshall(A,10);
//    printV(A,string("ワーシャルフロイド後の魔法コスト"));
    int cost=0;
    for(int j=0;j<H;j=j+1){
        for(int k=0;k<W;k=k+1){
            int x = Wall[j][k];
            if(x!=-1){
                cost=cost+A[x][1];
            }
        }
    }
    cout << cost << "\n" << flush;
    return 0;
}
