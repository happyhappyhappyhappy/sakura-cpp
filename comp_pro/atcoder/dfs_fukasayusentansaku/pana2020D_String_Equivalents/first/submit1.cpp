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
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
int N;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void dfs(string str,int pos){
    int length=(int)str.size();
    if(length == N){
        cout << str << "\n" << flush;
        return;
    }
    for(int j=0;j<pos;j=j+1){
        char x = 'a'+j;
        string nstr=str+x;
        dfs(nstr,pos);
    }
    char x = 'a'+pos;
    string nstr=str+x;
    // これで次のアルファベットを使える
    dfs(nstr,pos+1);
}
int main(void){
    initial();
    cin >> N;
    string str="";
    dfs(str,0);
    return 0;
}
