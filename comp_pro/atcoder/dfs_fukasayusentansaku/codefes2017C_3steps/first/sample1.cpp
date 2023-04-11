#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }

int N, M;
vector<int> G[210000];

int dir[210000];

bool isbi = true;
void dfs(int v, int d) {
	dir[v] = d;
	for (auto e : G[v]) {
		if (dir[e] == -1) {
			dfs(e, 1 - d);
		}
		else {
			if (dir[e] == 1 - d) continue;
			else isbi = false;
		}
	}
}

int main() {
	while (cin >> N >> M) {
		for (int i = 0; i < 210000; ++i) G[i].clear();
		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			--a, --b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		memset(dir, -1, sizeof(dir));
		dfs(0, 0);

		if (N <= 3) cout << 0 << endl;
		else {
			if (isbi) {
				int left = 0, right = 0;
				for (int i = 0; i < N; ++i) {
					if (dir[i] == 0) ++left;
					else ++right;
				}
				cout << (long long)left * right - M << endl;
			}
			else {
				cout << (long long)N * (N - 1) / 2 - M << endl;
			}
		}
	}
}

