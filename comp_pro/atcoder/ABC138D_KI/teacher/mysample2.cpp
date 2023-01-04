#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}
// 大域変数
Graph G; // 相関関係
int N,Q; // 根の数、追加する数
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

void dfs(int v,int p,vector<ll> &res){
    debug("v : %d , p : %d に入りました\n",v,p);
    if(p!=-1){
        res[v]=res[v]+res[p];
    }
    debug("現在のカウンターの形\n");
    for(int j=0;j < res.size();j=j+1){
        debug(" %lld ",res[j]);
    }
    debug("\n");
    showG();
    /* for(auto e: G[v]){
        if(e == p){
            debug("G[%d] にて e:%d == p:%d となりましたので検索抜けます\n",v,e,p);
            continue;
        }
        dfs(e,v,res);
    }
    */
    int V_size = G[v].size();
    for(int j=0;j<V_size;j=j+1){
        int e = G[v][j];
    if(e == p)
    {
        debug("G[%d][%d] -> e: %d == p:%d となりましたので再帰型深さ優先を抜けます\n",v,j,e,p);
        continue;
    }
    dfs(e,v,res);
}
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    cin >> N >> Q;
    debug("N = %d,Q = %d\n",N,Q);
    G.assign(N,vector<int>());
    for(int j = 0;j < N - 1;j=j+1){
        int a,b;
        cin >> a >> b;
        a = a-1;
        b = b-1; // -1;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> val(N,0);
    for(int j=0;j<Q;j=j+1){
        int p,x;
        cin >> p >> x;
        p = p -1;
        val[p] = val[p] + x;
    }
    for(auto &e:val){
        debug("%lld ",e);
    }
    debug("\n");
    dfs(0,-1,val);
    for (auto v:val)
    {
        cout << v << " ";
    }
    cout << "\n" << flush;
    return 0;
}

