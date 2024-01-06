#include <iostream>
#include <vector>
#include <algorithm>

constexpr long long INF = (1LL << 60);

// 辺
struct Edge
{
	int from;
	int to;
	int cost;
};

// ベルマンフォード法 (1.2 負閉路の影響を受ける頂点を調べる)
// 負の閉路が存在する場合 true を返し, 負閉路の影響を受ける頂点は -INF にセットされる
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
bool BellmanFord(const std::vector<Edge>& edges, std::vector<long long>& distances, int startIndex)
{
	distances[startIndex] = 0;

	for (size_t i = 0; i < distances.size(); ++i)
	{
		bool changed = false;

		// 各辺について
		for (const auto& edge : edges)
		{
			// (INF + cost) は INF なので処理しない
			if (distances[edge.from] == INF)
			{
				continue;
			}

			// to までの新しい距離
			const long long d = (distances[edge.from] + edge.cost);

			// d が現在の記録より小さければ更新
			if (d < distances[edge.to])
			{
				distances[edge.to] = d;

				changed = true;
			}
		}

		// どの頂点も更新されなかったら終了
		if (!changed)
		{
			return false;
		}
	}

	// 頂点数分だけさらに繰り返し, 負閉路の影響を受ける頂点に -INF を伝播
	for (size_t i = 0; i < distances.size(); ++i)
	{
		for (const auto& edge : edges)
		{
			if (distances[edge.from] == INF)
			{
				continue;
			}

			const long long d = (distances[edge.from] + edge.cost);

			if (d < distances[edge.to])
			{
				// 負閉路の影響を受ける頂点を -INF に
				distances[edge.to] = -INF;
			}
		}
	}

	return true;
}

int main()
{
	// N 頂点, M 辺, 1 分あたりのペナルティ P
	int N, M, P;
	std::cin >> N >> M >> P;

	std::vector<Edge> edges(M);
	for (auto& edge : edges)
	{
		std::cin >> edge.from >> edge.to >> edge.cost;
		--edge.from;
		--edge.to;
		edge.cost = (-edge.cost + P);
	}

	std::vector<long long> distances(N, INF);

	BellmanFord(edges, distances, 0);

	if (distances[N - 1] == -INF) // 頂点 N へと至る負閉路が存在する場合
	{
		std::cout << "-1\n";
	}
	else
	{
		std::cout << std::max(-distances[N - 1], 0LL) << '\n';
	}
}
