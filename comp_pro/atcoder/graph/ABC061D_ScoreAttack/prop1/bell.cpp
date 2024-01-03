// https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/bellman-ford

#include <iostream>
#include <vector>

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
