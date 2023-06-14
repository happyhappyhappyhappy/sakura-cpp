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
const int yamaMAX_INT = 1 << 30;
const ll yamaMAX_LL = 1LL << 60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int solver(int N,vector<vector<pair<int,int>> &E){
    int res=0;
    for(int j=0;j<N;j=j+1){
        vector<pair<int,int>> SList;
        SList = E[j];
        debug("Mr.%3d talk ",j);
        for(int k=0;(int)SList.size();k=k+1){
            pair<int,int> talk=SList[k];
            int w=talk.first;
            int horu=talk.second;
            debug("\t%3d is %3d\n",w,horu);
        }
        debug("\n");
    }
    return res;
}
int main(void){
    initial();
    int N=0;
    cin >> N;
    vector<vector<pair<int,int>> E;
    for(int j=0;j<N;j=j+1){
        int M=0;
        cin >> M;
        vector<pair<int,int>> SList;
        for(int k=0;k<M;k=k+1){
            int w=0;
            int horu=0;
            cin >> w >> horu ;
            SList[k]=make_pair(w-1,horu);
        }
        E.push_back(SList);
    }
    cout << solver(N,E) << "\n" << flush;
    return 0;
}
