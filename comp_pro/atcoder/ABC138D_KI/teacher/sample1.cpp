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
int N, Q;
vector<int> E[201010];
int val[201010];
//---------------------------------------------------------------------------------------------------
void dfs(int cu, int pa = -1) {
	#define fore(i,a) for(auto &i:a)
	fore(to, E[cu]) if(pa != to) {
		val[to] += val[cu];
		dfs(to, cu);
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> Q;
	rep(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--; b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	rep(q, 0, Q) {
		int p, x; cin >> p >> x;
		p--;
		val[p] += x;
	}

	dfs(0);

	rep(i, 0, N) {
		if (i) printf(" ");
		printf("%d", val[i]);
	}
	printf("\n");
}
