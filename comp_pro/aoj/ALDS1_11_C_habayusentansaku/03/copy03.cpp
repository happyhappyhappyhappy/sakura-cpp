#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/lib/dump.hpp"
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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void){
    initial();
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int j=0;j<N;j=j+1){
        int tmp,point;
        cin >> tmp >> point;
        for(int k=0;k<point;k=k+1){
            int nextpos;
            cin >> nextpos;
            nextpos=nextpos-1;
            G[j].push_back(nextpos);
        }
    }
    vector<int> dist(N,-1);
    queue<int> que;
    dist[0]=0;
    que.push(0);
    while(que.empty()==false){
        int pos=que.front();
        for(int j=0;j<(int)G[pos].size();j=j+1){
            int nextpos=G[pos][j];
            if(dist[nextpos]!=-1){
                continue;
            }else{
                que.push(nextpos);
                dist[nextpos]=dist[pos]+1;
            }
        }
        que.pop();
    }
    for(int j=0;j<N;j=j+1){
        cout << j+1 << " " << dist[j] << "\n" << flush;
    }
    return 0;
}
