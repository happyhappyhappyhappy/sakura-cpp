#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
int N, M, Q, a[50], b[50], c[50], d[50];
//---------------------------------------------------------------------------------------------------
int ans = 0;
int A[10];
void dfs(int cu = 0, int lst = 1) {
	if (cu == N) {
		int tot = 0;
		rep(i, 0, Q) if (A[b[i]] - A[a[i]] == c[i]) tot += d[i];
		chmax(ans, tot);
		return;
	}

	rep(nxt, lst, M + 1) {
		A[cu] = nxt;
		dfs(cu + 1, nxt);
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> Q;
	rep(i, 0, Q) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--; b[i]--;
	}

	dfs();
	cout << ans << endl;
}
