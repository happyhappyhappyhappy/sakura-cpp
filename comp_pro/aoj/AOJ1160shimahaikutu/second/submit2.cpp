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
using Graph=vector<vector<int>>;

Graph G;
int H,W;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showG(int hh,int ww, vector<vector<int>> G,int testcase){
    for(int h=0;h<hh;h=h+1){
        for(int w=0;w<ww;w=w+1){
            debug1(" %d",G[h][w]);
        }
        debug1("\n");
    }
}

int main(void){
    initial();
    int testcase=1;
    while(cin >> W >> H){
        if(W == 0 && H == 0){
            break;
        }
        debug1("----- testcase %d (%d,%d)-----\n",testcase,H,W);
        G.resize(H,vector<int>(W,0));
        for(int h=0;h<H;h=h+1){
            for(int w=0;w<W;w=w+1){
                int h1,w1,v;
                cin >> G[h][w];
            }
        }
        showG(H,W,G,testcase);
        for(int j=0;j < H;j=j+1){
            for(int k=0;k<W;k=k+1){
                cout << " " << G[j][k];
            }
            cout << "\n" << flush;
        }
        testcase=testcase+1;
    }
    return 0;
}

