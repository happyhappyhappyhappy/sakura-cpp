#include<bits/stdc++.h>
#ifdef LOCAL
#include"/code/sakura-cpp/comp_pro/debug.h"
#include"/code/sakura-cpp/comp_pro/t_debug.h"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;

using ll=long long;
using fr=first;
using sc=second;
using Pt=pair<int,int>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;
const vector<int> dw={0,1,0,-1};
const vector<int> dh={1,0,-1,0};
int W,H;
vector<vector<int>>  cost(30,vector<int>(30,0));
vector<vector<vector<vector<bool>>>> mas(30,vector<bool>(30,vector<bool>(30,vector<bool>(30,vector<bool>(30)))));
int bfs(){
    cost.assign(30,vector<int>(30,0));
}
