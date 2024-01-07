#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
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






typedef long long ll;
int N, A[303][303];
ll d[303][303];
#define INF INT_MAX/2
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) rep(j, 0, N) cin >> A[i][j];

    vector<pair<ll, pair<int, int>>> v;
    rep(i, 0, N) rep(j, i + 1, N) v.push_back({ -A[i][j],{ i,j } });
    sort(v.begin(), v.end());

    ll ans = 0;
    rep(i, 0, N) rep(j, i + 1, N) ans += A[i][j];
    fore(p, v) {
        ll c = -p.first;
        int a = p.second.first;
        int b = p.second.second;
        if (A[a][b] == INF) continue;

        rep(i, 0, N) if (i != a && i != b && A[a][i] != INF && A[i][b] != INF) {
            if (A[a][i] + A[i][b] == c) {
                ans -= c;
                A[a][b] = A[b][a] = INF;
                break;
            } else if (A[a][i] + A[i][b] < c) {
                printf("-1\n");
                return;
            }
        }
    }
    cout << ans << endl;
}
