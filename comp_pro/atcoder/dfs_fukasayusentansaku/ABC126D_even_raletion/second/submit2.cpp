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
using Edge=pair<int,ll>;
using Stem=tuple<int,int,int>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(int &N,vector<vector<Edge>> &G,vector<int> &c_code){
    stack<Stem> S;

    S.push(make_tuple(0,-1,1));
    while(S.empty()==false){
        Stem st=S.top();
        int to = get<0>(st);
        int from = get<1>(st);
        int ncolor = get<2>(st);
        c_code[to]=ncolor;
        S.pop();
        for(int j=0;j<(int)G[to].size();j=j+1){
            Edge e = G[to][j];
            if(e.first == from){
                continue;
            }
            else{
                ll dist=e.second;
                if(dist & 1){
                    Stem nextS=make_tuple(e.first,to,1-c_code[to]);
                    S.push(nextS);
                }
                else{
                    Stem nextS=make_tuple(e.first,to,c_code[to]);
                    S.push(nextS);
                }
            }
        }
    }
    // 下はとりあえずデータは正しく出ていることを確認するまで。
/*
    for(int j=0;j<N;j=j+1){
        debug("根[%5d]について関連している木\n",j);
        for(int k=0;k<(int)G[j].size();k=k+1){
            Edge e = G[j][k];
            int r=e.first;
            ll d=e.second;
            if()
            // debug("-> %d : %lld  \n",r,d);
        }
    }
*/
}

int main(void){
    initial();
    int N;
    cin >> N;
    vector<vector<Edge>> G(N,vector<Edge>());
    vector<int> c_code(N,0);
    for(int j=0;j<N-1;j=j+1){
        int from,to;
        ll dist;
        cin >> from >> to >> dist;
        from=from-1;
        to=to-1;
        G[to].push_back(Edge(from,dist));
        G[from].push_back(Edge(to,dist));
    }
    solve(N,G,c_code);
    for(int j=0;j<N;j=j+1){
        cout << c_code[j] << " ";
    }
    cout << "\n" << flush;
    return 0;
}

