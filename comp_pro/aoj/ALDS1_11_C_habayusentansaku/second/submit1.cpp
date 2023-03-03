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

int main(void){
    initial();
    int Umax;
    cin >> Umax;
    vector<vector<int>> G(Umax);
    for(int r=0;r<Umax;r=r+1){
        int tmp,num;
        cin >> tmp >> num;
        for(int c=0;c<num;c=c+1){
            int nextpos;
            cin >> nextpos;
            G[r].push_back(nextpos-1);
        }
    }
    // for(int r=0;r<Umax;r=r+1){
    //     int cpos = (int)G[r].size();
    //     cout << r << " : ";
    //     for(int c=0;c<cpos;c=c+1){
    //         cout << " " << G[r][c];
    //     }
    //     cout << "\n" << flush;
    // }
    // 初期設定
    vector<int> dist(Umax,-1);
    queue<int> que;
    dist[0]=0;
    que.push(0);
    while(que.empty()==false){
        int nowpos=que.front();
        for(int j=0;j<(int)G[nowpos].size();j=j+1){
            int nextpos=G[nowpos][j];
            if(dist[nextpos]!=-1){
                continue;
            }
            else
            {
                dist[nextpos]=dist[nowpos]+1;
                que.push(nextpos);
            }
        }
        que.pop();
    }
    for(int j=0;j<Umax;j=j+1){
        cout << j+1 << " " << dist[j] << "\n" << flush;
    }
    return 0;
}
