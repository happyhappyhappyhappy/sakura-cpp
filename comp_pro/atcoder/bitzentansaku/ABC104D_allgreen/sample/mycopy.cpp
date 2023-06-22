#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;

int D;
long long G;
vector<long long> p, c;

int main() {
  cin >> D >> G;
  p.resize(D); c.resize(D);
  for (int i = 0; i < D; ++i) cin >> p[i] >> c[i];

  long long res = 1<<29;
  for (int bit = 0; bit < (1<<D); ++bit) {
    long long sum = 0;
    long long num = 0;
    for (int i = 0; i < D; ++i) {
      if (bit & (1<<i)) {
        debug("%d 問目を解いたと仮定\n",i);
        sum += c[i] + p[i] * 100 * (i+1);
        num += p[i];
    }
    debug("bitで示した合計分の点数 %3lld\n",sum);
    if (sum >= G) res = min(res, num);
    else {
      for (int i = D-1; i >= 0; --i) {
        if (bit & (1<<i)) continue;
        for (int j = 0; j < p[i]; ++j) {
          if (sum >= G) break;
          sum += 100 * (i+1);
          ++num;
        }
      }
      res = min(res, num);
    }
  }
  cout << res << endl;
}
