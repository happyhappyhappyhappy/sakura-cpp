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
    string bitChain;
    for(int j=0;j<D;j=j+1){
        int bitChk = 1<<j;
        int bitAns = bit & bitChk;
        debug("..... %d と %dをクロス => %d\n",bit,bitChk,bitAns);
        if(bitAns){
          bitChain.append("1");
        }
        else{
          bitChain.append("0");
        }
    }
    debugt(bitChain);
    for (int i = 0; i < D; ++i) {
      if (bit & (1<<i)) {

        sum += c[i] + p[i] * 100 * (i+1), num += p[i];
        debug("%d 番目を解いたら 合計点 %lld 問題数 %lldになった\n",
        i,sum,num);
        }
    }// for i=0;i<D;++i
    if (sum >= G) {
      debug("%u, 合計点 %lld が %lld突破 num=%lldを比較\n"
      ,__LINE__,sum,G,num);
      res = min(res, num);
      }
    else {
      debug("%u, 合計点 %lldで 突破出来なかったので貪欲法へ行った\n"
      ,__LINE__,sum);
      for (int i = D-1; i >= 0; --i) {
        if (bit & (1<<i)) continue;
        for (int j = 0; j < p[i]; ++j) {
          if (sum >= G) break;
          sum += 100 * (i+1);
          ++num;
        }
      }
      debug("%u. 最終的には 合計 %lld点になった。解いた問題数%lldでセット\n",
      __LINE__,sum,num);
      res = min(res, num);
    }
  }
  cout << res << endl;
}
