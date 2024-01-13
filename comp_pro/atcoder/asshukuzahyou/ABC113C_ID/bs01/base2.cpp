#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/






int N, M;
vector<pair<int,int>> E[101010];
string ans[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, M) {
        int p, y; cin >> p >> y;
        E[p].push_back({ y, i });
    }
    rep(i, 1, N + 1) {
        sort(all(E[i]));
        int n = E[i].size();
        rep(j, 0, n) {
            char buf[13];
            sprintf(buf, "%06d%06d", i, j + 1);
            ans[E[i][j].second] = string(buf);
        }
    }
    rep(i, 0, M) printf("%s\n", ans[i].c_str());
}
