#include <iostream>
#include <vector>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

// 入力
int H, W;
vector<vector<int>> field;

// 探索
void dfs(int h, int w) {
    field[h][w] = 0;

    // 八方向を探索
    for (int dh = -1; dh <= 1; ++dh) {
        for (int dw = -1; dw <= 1; ++dw) {
            int nh = h + dh, nw = w + dw;

            // 場外アウトしたり、0 だったりはスルー
            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (field[nh][nw] == 0) continue;

            // 再帰的に探索
            debug("\n->Next(%d,%d)\n",nh,nw);
            dfs(nh, nw);
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

int main() {
    // 入力受け取り
    while (cin >> W >> H) {
        debug("\n Start [%d,%d]\n",W,H);
        if (H == 0 || W == 0) break;
        field.assign(H, vector<int>(W, 0));
        for (int h = 0; h < H; ++h) for (int w = 0; w < W; ++w) cin >> field[h][w];

        // 探索開始
        int count = 0;
        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                if (field[h][w] == 0) continue; // 残島じゃなかったらスルー
                debug("\nNext (%d,%d)\n",h,w);
                dfs(h, w);
                ++count;
            }
        }
        cout << count << endl;
    }
}
