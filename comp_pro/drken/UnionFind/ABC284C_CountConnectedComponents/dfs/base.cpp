#include <bits/stdc++.h>
using namespace std;

// グラフ
using Graph = vector<vector<int>>;

// 頂点 v を始点とする DFS
// seen[v] := 頂点 v が探索済みならば true / そうでなければ false
void dfs(const Graph &G, int v, vector<bool> &seen) {
    // 頂点 v を探索済みにする
    seen[v] = true;

    // 頂点 v に隣接する各頂点 v2 を順に探索する
    for (auto v2 : G[v]) {
        // 頂点 v2 が探索済みならばスキップ
        if (seen[v2]) continue;

        // 再帰的に探索
        dfs(G, v2, seen);
    }
}

int main() {
    // 入力受け取り
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // DFS
    int res = 0;
    vector<bool> seen(N, false);
    for (int v = 0; v < N; ++v) {
        // 頂点 v を含む連結成分がすでに探索済みの場合はスキップ
        if (seen[v]) continue;

        // 頂点 v を始点とする DFS を行う
        // このとき、頂点 v を含む連結成分の全体を探索することとなる
        ++res;
        dfs(G, v, seen);
    }
    cout << res << endl;
}
