#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 30;

// 「分野別 初中級者が解くべき過去問精選 100問」の問題7
// https://qiita.com/e869120/items/eb50fdaece12be418faa
// 
// https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c

/*
 * 
 * 
 */
int main(void)
{
	int i, j;
	int N;
	cin >> N;
	vector<int> x(N), y(N);
	set<pair<int,int>> xy_set;
	for(i = 0; i < N; i++)
	{
		cin >> x[i] >> y[i];
		xy_set.insert({x[i], y[i]});
	}

	int answer = 0;
	for(i = 0; i < N; i++)
	{
		for(j = i+1; j < N; j++)
		{
			int dx = x[i]-x[j];
			int dy = y[i]-y[j];

			if( (xy_set.find({x[i]+dy, y[i]-dx}) != xy_set.end() && xy_set.find({x[j]+dy, y[j]-dx}) != xy_set.end() )
				|| (xy_set.find({x[i]-dy, y[i]+dx}) != xy_set.end() && xy_set.find({x[j]-dy, y[j]+dx}) != xy_set.end() ) )
			{
				// 三平方の定理より、(正方形の辺の長さ)=√(dx*dx+dy*dy) となる。
				// よって面積は dx*dx+dy*dy で求められる。
				answer = max(answer, dx*dx+dy*dy);
			}
		}
	}
	cout << answer << endl;

	// dx, dyだったときに、
	// {dy, -dx}と{-dy, dx}に柱があるか
	return 0;
}
