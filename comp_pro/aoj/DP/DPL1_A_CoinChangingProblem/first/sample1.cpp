#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <math.h>

#define ll long long
#define Int int
#define loop(x, start, end) for(Int x = start; x < end; x++)
#define loopdown(x, start, end) for(int x = start; x > end; x--)
#define rep(n) for(int x = 0; x < n; x++)
#define span(a,x,y) a.begin()+x,a.begin()+y
#define span_all(a) a.begin(),a.end()
#define len(x) (x.size())
#define last(x) (*(x.end()-1))

using namespace std;
#define W_MAX 10000
#define INF 10001
#define N_MAX 50001
#define M_MAX 21
Int min_coin() {
  loop(n,0,N+1) {
    table[0][n] = INF;
  }
  loop(m,0,M+1) {
    table[m][0] = 0;
  }

  loop(m,1,M+1) {
    Int coin = COINS[m];
    loop(n,1,N+1) {
      if (n - coin < 0) {
        table[m][n] = table[m-1][n];
        continue;
      }

      table[m][n] = min(table[m-1][n], table[m][n-coin] + 1);
    }
    showDP(M,N);
  }

  return table[M][N];
}

int main(void) {
  cin >> N >> M;
  COINS[0] = 0;
  loop(i,1,M+1) {
    cin >> COINS[i];
  }

  cout << min_coin() << endl;
}
