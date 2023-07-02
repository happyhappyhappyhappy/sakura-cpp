#include<bits/stdc++.h>
// 失敗版 辞書順に失敗した
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
using dfs=pair<string,int>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
int N;
vector<string> STR;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
}
void solver(void){

    stack<dfs> S;
    dfs firstS=make_pair("",0);
    S.push(firstS);
    while(S.empty()==false){
        dfs val=S.top();
        S.pop();
        string str=val.first;
        int pos=val.second;
        debug("スタックから 文字列 %s pos %d を取り出しました\n",
        str.c_str(),pos);
        int length=int(str.size());
        if(length==N){
            STR.push_back(str);
        }else{
            for(int j=0;j<pos;j=j+1){
                char x = 'a'+j;
                string nstr=str+x;
                dfs nset = make_pair(nstr,pos);
                debug("スタックに 文字列 %s,pos %d を入力します\n",
                nset.first.c_str(),nset.second);
                S.push(nset);
            }
            char x = 'a'+pos;
            string nstr=str+x;
            dfs npair=make_pair(nstr,pos+1);
            debug("スタックに 文字列 %s,pos %d を入力します\n",
            npair.first.c_str(),npair.second);
            S.push(npair);
        }
    }
}
int main(void){
    initial();
    solver();
    // TODO: STRをソートし、出力してください2023-07-01 19:31:34
    // 不安であればvector<string> のソースサンプルを作ってみる
    return 0;
}
