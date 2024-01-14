#include <bits/stdc++.h>
using namespace std;

int main() {
    // 入力
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

    // 座標圧縮の準備
    auto nX = X, nY = Y;
    sort(nX.begin(), nX.end());
    nX.erase(unique(nX.begin(), nX.end()), nX.end());
    sort(nY.begin(), nY.end());
    nY.erase(unique(nY.begin(), nY.end()), nY.end());

    // 座標圧縮
    for (int i = 0; i < N; ++i) {
        int xres = lower_bound(nX.begin(), nX.end(), X[i]) - nX.begin();
        int yres = lower_bound(nY.begin(), nY.end(), Y[i]) - nY.begin();
        cout << xres+1 << " " << yres+1 << endl;
    }
}
