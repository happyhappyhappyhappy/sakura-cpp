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

void solver(string str,int pos){
    debug("現在の位置 %3d\n",pos);
    if((int)str.size()==N){
        debug("cout を行います 中身 %s\n",str.c_str());
        cout << str << "\n" << flush;
        return ;
    }
    for(int j=0;j<pos;j=j+1){
        debug("for文中 j=%3d\n",j);
        char c='a'+j;
        string strpc = str+c;
        debug("%s にして %3d 番目 として再帰します\n",strpc.c_str(),pos);
        solver(str+c,pos);
    }
    char c='a'+pos;
    string strpc=str+c;
    debug("%sにして %3d 番目で再帰します\n",strpc.c_str(),pos+1);
    solver(str+c,pos+1);
}

int main(void){
    initial();
    cin >> N;
    string str="";
    solver(str,0); // デフォルトもきちんと代入
    return 0;
}
