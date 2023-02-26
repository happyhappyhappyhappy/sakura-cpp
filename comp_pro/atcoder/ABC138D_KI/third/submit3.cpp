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

void dfs(int n_pos,int p_pos,vector<int> &value,vector<vector<int>> &T)
{
    if(p_pos!=-1){ // 上の根から来た値を追加する(いもす法)
        value[n_pos]=value[p_pos]+value[n_pos];
    }
    for(int j=0;j<(int)T[n_pos].size();j=j+1){
        if(T[n_pos][j]==p_pos){
            // 上の節はもう進まないので却下
            continue;
        }
        else{
            debug(n_pos);
            debug(j);
            // 下に渡していく
            dfs(T[n_pos][j],n_pos,value,T);
        }
    }
}

void showT(vector<vector<int>> &T,int J){
    for(int j=0;j<J;j=j+1){
        debug1(" %d : ",j);
        for(int k=0;k<(int)T[j].size();k=k+1){
            debug1(" %d",T[j][k]);
        }
        debug1(" \n");
    }
}

int main(void){
    initial();
    int N,Q;
    cin >> N >> Q;
    vector<vector<int>> T(N);
    vector<int> value(N,0);
    for(int j=0;j<N-1;j=j+1){
        int first,second;
        int first0,second0; // 0-indexに替えた物
        cin >> first >> second;
        first0=first-1;
        second0=second-1;
        T[first0].push_back(second0);
        T[second0].push_back(first0);
    }
    for(int q=0;q<Q;q=q+1){
        int pos,val;
        cin >> pos >> val;
        debug1("before pos = %d\n",pos);
        pos = pos - 1; // 0-indexにする
        debug1("after pos = %d\n",pos);
        debug(q);
        debug(pos);
        debug(val);
        value[pos]=value[pos]+val;
        debug(value[pos]);
    }
    dfs(0,-1,value,T);
    for(int j=0;j<N;j=j+1){
        cout << value[j] << " ";
    }
    cout << "\n" << flush;
    return 0;
}

