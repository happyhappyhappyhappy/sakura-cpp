#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int H, W, A, B;
//---------------------------------------------------------------------------------------------------
bool used[16][16];
// x <=> W,y <=> Hとして値を見ていく
// used[y][x] -> 最終的には used[H][W]と見ると分かりやすい
int dfs(int x, int y, int a) {
	// 最後まで探索して、長方形のタイルを使い切っているなら、組合せを+1する
	if (H == y) return a == 0;

	// 横の端まで行ったら次の行へ
	if (W == x) return dfs(0, y + 1, a);

	// 既に置かれているなら何もできないので、次のマスへ
	if (used[y][x]) return dfs(x + 1, y, a);

	int res = 0;

	// 縦置き
	if (y + 1 < H && !used[y + 1][x] && 0 < a) {
		used[y][x] = used[y + 1][x] = true;
		res += dfs(x + 1, y, a - 1);
		used[y][x] = used[y + 1][x] = false;
	}

	// 横置き
	if (x + 1 < W && !used[y][x + 1] && 0 < a) {
		used[y][x] = used[y][x + 1] = true;
		res += dfs(x + 1, y, a - 1);
		used[y][x] = used[y][x + 1] = false;
	}

	// 何も置かない
	res += dfs(x + 1, y, a);

	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W >> A >> B;
	cout << dfs(0, 0, A) << endl;
}
