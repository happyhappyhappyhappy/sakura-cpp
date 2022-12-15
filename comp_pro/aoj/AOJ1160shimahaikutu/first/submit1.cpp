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

bool out_of_Grid(int y,int x){
    if(y<0){
        return true;
    }
    if(x<0){
        return true;
    }
    if(H<=y){
        return true;
    }
    if(W<=x){
        return true;
    }
    return false;
}

void dfs(vector<vector<int>> &G,int h,int w){
    G[h][w]=0; // 自分の所は探索済みにする
    for(int dx = -1;dx <= 1;dx=dx+1){
        for(int dy = -1;dy <=1 ;dy=dy+1){
            if(out_of_Grid(h+dy,w+dx))
            {
                continue;
            }
            dfs(G,h+dy,w+dx);
        }
    }
}
void show1(vector<vector<int>> &G,int h,int w)
{
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


