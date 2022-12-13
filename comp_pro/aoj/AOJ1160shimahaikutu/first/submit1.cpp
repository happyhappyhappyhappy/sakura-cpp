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


void dfs(vector<vector<int>> &G,int h,int w){
    G[h][w]=0; // 自分の所は探索済みにする
    for(dx = -1;dx <= 1;dx=dx+1){
        for(dy = -1;dy <=1 ;dy=dy+1){
            // TODO: ここから 八方向探索
            // 解説 https://qiita.com/drken/items/a803d4fc4a727e02f7ba#%E3%82%B0%E3%83%AA%E3%83%83%E3%83%89%E3%82%B0%E3%83%A9%E3%83%95%E3%81%AE%E5%A0%B4%E5%90%88%E3%81%AE%E9%A1%9E%E9%A1%8C
            // 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp
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
        int count;
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
    }
    return 0;
}


