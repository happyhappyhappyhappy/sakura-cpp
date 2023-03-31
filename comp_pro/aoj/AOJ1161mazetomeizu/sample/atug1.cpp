#include <bits/stdc++.h>
using namespace std;

void read_wall(int h, int w, int wall_vert[30][30], int wall_hori[30][30])
{
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w - 1; ++j)
            cin >> wall_vert[i][j];
        if (i == h - 1)
            continue;
        for (int j = 0; j < w; ++j)
            cin >> wall_hori[i][j];
    }
}

bool can_go(int h, int w, int wall_vert[30][30], int wall_hori[30][30],
            int x, int y, int dx, int dy) // dx, dy は移動の差分
{
    assert(-1 <= dx && dx <= 1);
    assert(-1 <= dy && dy <= 1);
    assert(dx == 0 || dy == 0);
    int x2 = x + dx, y2 = y + dy;
    if (x2 < 0 || h <= x2 || y2 < 0 || w <= y2) // 迷路の外側判定
        return false;
    if (dx > 0 && wall_hori[x][y] == 1) // 下への移動判定
        return false;
    if (dx < 0 && wall_hori[x2][y] == 1) // 上への移動判定
        return false;
    if (dy > 0 && wall_vert[x][y] == 1) // 右への移動判定
        return false;
    if (dy < 0 && wall_vert[x][y2] == 1) // 左への移動判定
        return false;
    return true;
}

int main()
{
    int h, w;
    int wall_vert[30][30] = {};
    int wall_hori[30][30] = {};
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (cin >> w >> h) {
        if (h == 0 && w == 0)
            return 0;
        read_wall(h, w, wall_vert, wall_hori);
        int dist[30][30] = {};
        queue<pair<int, int>> que;
        dist[0][0] = 1;
        que.push({0, 0});
        while (!que.empty()) {
            auto pr = que.front(); que.pop();
            int x = pr.first;
            int y = pr.second;
            for (int i = 0; i < 4; ++i) {
                if (!can_go(h, w, wall_vert, wall_hori, x, y, dx[i], dy[i]))
                    continue;
                int x2 = x + dx[i];
                int y2 = y + dy[i];
                if (dist[x2][y2] > 0)
                    continue;
                dist[x2][y2] = dist[x][y] + 1;
                que.push({x2, y2});
            }
        }
        cout << dist[h - 1][w - 1] << endl;
    }
}
