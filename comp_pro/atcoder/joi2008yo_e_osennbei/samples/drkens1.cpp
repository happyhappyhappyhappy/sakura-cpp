#include <bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)

void fixPos(int bit,int bitsize){
    for(int j=0;j<bitsize;j=j+1){
        if()
        debug("%dは固定されています",j);
    }
}

int main() {
    int H, W;
    cin >> H >> W;
    vector fi(H, vector(W, 0));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> fi[i][j];
    int res = 0;
    for (int bit = 0; bit < (1<<H); ++bit) {
        fixPos(bit,H);
        auto fi2 = fi;
        for (int i = 0; i < H; ++i) {
            if (!(bit & (1<<i))) continue;
            for (int j = 0; j < W; ++j) fi2[i][j] = 1 - fi2[i][j];
        }
        int tmp = 0;
        for (int j = 0; j < W; ++j) {
            int num = 0;
            for (int i = 0; i < H; ++i) if (fi2[i][j] == 0) ++num;
            tmp += max(num, H-num);
        }
        res = max(res, tmp);
    }
    cout << res << endl;
}
