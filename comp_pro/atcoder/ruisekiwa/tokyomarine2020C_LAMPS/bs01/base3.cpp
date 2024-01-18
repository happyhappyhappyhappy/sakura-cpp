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














int N, K, A[201010], B[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> A[i];

	rep(k, 0, K) {
		rep(i, 0, N) B[i] = 0;
		rep(i, 0, N) {
			int L = max(0, i - A[i]);
			int R = min(N - 1, i + A[i]);

			B[L]++;
			B[R + 1]--;
		}
		rep(i, 1, N) B[i] += B[i - 1];

		bool same = true;
		rep(i, 0, N) {
			if (A[i] != B[i]) same = false;
			A[i] = B[i];
		}

		if (same) break;
	}

	rep(i, 0, N) {
		if(i) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}
