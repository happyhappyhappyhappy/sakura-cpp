#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

int H,W;

bool out_of_Grid(int nh,int nw,int H,int W){
    if(nh<0){
        return true;
    }
    if(nw<0){
        return true;
    }
    if(H<=nh){
        return true;
    }
    if(W<=nw){
        return true;
    }
    return false;
}

void dfs(vector<vector<int>> &G,int h,int w){
    int gw = G[0].size();
    int gh = G.size();
    G[h][w]=0; // 自分の所は探索済みにする
    for(int dw = -1;dw <= 1;dw=dw+1){
        for(int dh = -1;dh <=1 ;dh=dh+1){
            int nh = h+dh;
            int nw = w+dw;
            if(out_of_Grid(nh,nw,gh,gw))
            {
                continue;
            }
            if(G[nh][nw]==0){
                continue;
            }
            dfs(G,nh,nw);
        }
    }
}
void show1(vector<vector<int>> &G)
{
    int nh = G.size();
    int nw = G[0].size();
    for(int j=0;j<nh;j=j+1){
        for(int k=0;k<nw;k=k+1){
            if(G[j][k]==1){
                debug(" o");
            }
            else{
                debug(" x") ;
            }
        }
        debug("\n");
    }
    debug("\n\n");
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int W;
    int H;
    while(cin >> W >> H){
        if(H == 0 || W == 0)break;
        // debug("\n地図[%d,%d]の深さ優先探索開始\n",H,W);
        vector<vector<int>> G(H,vector<int>(W,0));
        for(int j=0;j<H;j=j+1){
            for(int k=0;k<W;k=k+1){
                cin >> G[j][k];
            }
        }
        int count=0;
        for(int h=0;h<H;h=h+1){
            for(int w=0;w<W;w=w+1){
                if(G[h][w]==0){
                    continue;
                }
                // debug("\n段階 %dの地図の様子\n",count+1);
//                show1(G);
                dfs(G,h,w);
                count = count+1;
            }
        }
        /**
        for(int j=0;j<H;j=j+1){
            for(int k=0;k<W;k=k+1){
                if(G[j][k]==1){
                    cout << " o" ;
                }
                else{
                    cout << " x" ;
                }
            }
            cout << "\n" << flush;
        }
        cout << "\n\n" << flush;
        **/
       cout << count << "\n" << flush;
    }

    return 0;
}
/**
± % ./a.out < testcase1.txt                                    !1499
0
2
6
8
14
9
**/


