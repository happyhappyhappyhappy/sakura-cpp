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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showG(vector<vector<int>> G){
    int P=(int)G.size();
    for(int j=0;j<P;j=j+1){
        debug(G[j]);
    }
}

int main(void){
    initial();
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int j=0;j<N;j++){
        int tmp,point;
        cin >> tmp >> point;
        point = point -1 ; // 0-indexに修正
        for(int k=0;k<point;k=k+1){
            int nextpos;
            cin >> nextpos;
            nextpos=nextpos-1; // 0-indexに修正

            G[j].push_back(nextpos);
            G[nextpos].push_back(j);
        }
    }
    showG(G);
    return 0;
}

