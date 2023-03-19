#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug1(...) 42
#define debug2(...) 42
#define debug(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
using Edge=pair<int,long long>;
using P2P=pair<int,int>; // 根から根情報 TO,FROM
using Graph=vector<vector<Edge>>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

Graph G;
vector<int> c_code;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solver(void){
    debug1("solverの中\n");
    stack<P2P> mystack;
    // まずGの中を確認してみる
    /*
    for(int j=0;j<(int)G.size();j=j+1){
        debug1("根 %d のやりとり\n",j);
        for(int k=0;k<(int)G[j].size();k=k+1){
            Edge now_e = G[j][k];
            debug(now_e);
            debug1("%d に対して 長さ %lld\n",
            now_e.first,now_e.second);
        }
    }*/
    // 根本的な所「0」の情報を与えてwhileを回す
    P2P baseT = make_pair(0,-1);
    c_code[0]=0;
    mystack.push(baseT);
    while(mystack.empty()==false){
        P2P npos = mystack.top();
        mystack.pop();
        if(npos.second != -1){
            for(int j=0;j<(int)G[npos.first].size();j=j+1){
                Edge nextpos = G[npos.first][j];
                int nextpos_ind = nextpos.first;
                ll nextpos_dis = nextpos.second;
                if(nextpos_ind == npos.second){
                    debug1("上に戻っているだけなので無視\n");
                    continue;
                }
                else{
                    if(int(nextpos_dis & 1)==1){
                        // TODO: c_codeセットしているかコマンド出してみて
                        c_code[nextpos_ind]=1-c_code[npos.first];

                        mystack.push(make_pair(nextpos_ind,npos.first));
                    }
                    else{
                        c_code[nextpos_ind]=c_code[npos.first];
                        mystack.push(make_pair(nextpos_ind,npos.first));
                    }
                }
            }
        }
    }
}

int main(void){
    initial();
    int N; cin >> N;
    G.assign(N,vector<Edge>());
    c_code.assign(N,0);
    for(int j=0;j<N-1;j++){
        int u,v;
        cin >> u >> v;
        ll w;
        cin >> w;
        u=u-1;
        v=v-1;
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    solver();
    for(int j=0;j<N;j=j+1){
        cout << c_code[j] << " ";
    }
    cout << "\n" << flush;
    return 0;
}
