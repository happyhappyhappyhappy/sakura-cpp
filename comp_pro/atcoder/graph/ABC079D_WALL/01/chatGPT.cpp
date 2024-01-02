#include <iostream>
#include <vector>
using namespace std;

// 無限大の値を定義（例えば INT_MAX など）
const int INF = 1000000000;

// ワーシャルフロイド法の実装
void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int V; // 頂点数
    cin >> V;
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // グラフの初期化（例：辺の重みの入力）
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
        }
    }
    // ワーシャルフロイド法の実行
    floydWarshall(dist, V);
    // 結果の出力
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
