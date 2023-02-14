#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/touristdebug.h"
#else
#define debug1(...) 42
#define debug2(...) 42
#define debug(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showG(int X,int Y, vector<vector<int>> &G,int testcase){
    debug1("----- testcase No. %d -----\n",testcase);
    for(int j=0;j<X;j=j+1){
        for(int k=0;k<Y;k=k+1){
            debug1(" %d",G[j][k]);
        }
        debug1("\n");
    }
}

int main(void){
    initial();
    int testcase=1;
    int W=0,H=0;
    vector<vector<int>> G;
    while(cin >> W >> H){
        if(W == 0 && H == 0){
            break;
        }
        // int H2 = H+2;
        // int W2 = W+2;
        // cout << H2 << " " << W2 << "\n" << flush;
        G.assign(H+2,vector<int>(W+2,-1));
        for(int h=1;h<=H;h=h+1){
            for(int w=1;w<=W;w=w+1){
                cin >> G[h][w];
            }
        }
        showG((int)H+2,(int)W+2,G,testcase);
        int answer=0;
        for(int j=0;j<H+2;j=j+1){
            for(int k=0;k<W+2;k=k+1){
                if(G[j][k] == 1){
                    search(j,k);
                }
            }
        }
        cout << answer << "\n" << flush;
        testcase=testcase+1;
    }
    return 0;
}

