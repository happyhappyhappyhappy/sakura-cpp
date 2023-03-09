#include <iostream>
#include <queue>
using namespace std;

int H, W, sx, sy, gx, gy;
char c[1009][1009];
int dist[1009][1009];
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> H >> W >> sx >> sy >> gx >> gy;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) dist[i][j] = (1 << 30);
	}

	Q.push(make_pair(sx, sy)); dist[sx][sy] = 0;
	while (!Q.empty()) {
		int px = Q.front().first, py = Q.front().second; Q.pop();
		for (int i = 0; i < 4; i++) {
			int qx = px + dx[i], qy = py + dy[i];
			if (c[qx][qy] != '.') continue;
			if (dist[qx][qy] != (1 << 30)) continue;
			dist[qx][qy] = dist[px][py] + 1;
			Q.push(make_pair(qx, qy));
		}
	}
	cout << dist[gx][gy] << endl;
	return 0;
}
