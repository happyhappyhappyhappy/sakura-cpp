#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define debug(...) fprintf(stderr,__VA_ARGS__)
int N, Q;
Graph G;

void showG(void){
    int H = G.size();
    int W;
    for(int h=0;h<H;h=h+1){
        int W = G[h].size();
        debug("%d : ",h);
        for(int w=0;w<W;w=w+1){
            debug(" %d",G[h][w]);
        }
        debug("\n");
    }
}

void dfs(int v, int p, vector<long long> &res) {
  debug("v = %d,p = %d に入りました\n",v,p);
  if (p != -1) res[v] += res[p];
  for (auto e : G[v]) {
    debug("---%dでshowG() start---\n",e);
    showG();
    debug("---%dでshowG() end ---\n",e);
    if (e == p) continue;
    dfs(e, v, res);
  }
}

int main() {
  cin >> N >> Q;
  G.assign(N, vector<int>());
  for (int i = 0; i < N-1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  showG();
  vector<long long> val(N, 0);
  for (int i = 0; i < Q; ++i) {
    int p, x;
    cin >> p >> x;
    --p;
    val[p] += x;
  }
  dfs(0, -1, val);
  for (auto v : val) cout << v << " ";
  cout << endl;
}
