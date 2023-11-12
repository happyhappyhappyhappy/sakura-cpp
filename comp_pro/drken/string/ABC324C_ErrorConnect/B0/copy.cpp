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
    string T;
    cin >> N >> T;
    vector<string> S(N);
    for(int j=0;j<N;j=j+1){
        cin >> S[j];
    }
    vector<int> res;
    for(int j=0;j<N;j=j+1){
        if(abs((int)S[j].size()-(int)T.size())>1){
            continue;
        }
        int pre = 0;
        int suf = 0;
        for(pre=0;pre<min((int)S[j].size(),(int)T.size());pre=pre+1){
            if(S[j][pre]!=T[pre]){
                break;
            }
        }
        for(suf=0;suf<min((int)S[j].size(),(int)T.size());suf=suf+1)
        {
            if(S[j][(int)S.size()-1-suf]!= T[(int)T.size()-1-suf]){
                break;
            }
        }
        int ssize=(int)S[j].size();
        int tsize=(int)T.size();
        debug("%d番目 : 先頭と等しい %d , 後ろからと等しい %d\n",j+1,pre,suf);
        debug("Si = Tの判定\n");
        if((ssize == tsize) &&(suf==tsize)){
            debug("p1.OK!\n");
            res.push_back(j+1);continue;
        }
        debug("Siに文字を代入すればTになる判定\n");
        if((ssize+1 == tsize) && (suf+pre==ssize)){
            debug("p2.OK!\n");
            res.push_back(j+1);continue;
        }
        debug("Siから文字を削除すればTになる判定\n");
        if((ssize-1==tsize)&&(suf+pre==tsize))
        {
            debug("p3.OK\n");
            res.push_back(j+1);
            continue;
        }
        debug("Siの文字を一文字変更すればTになる");
        if((ssize==tsize)&&(pre+suf+1==tsize)){
            debug("p4.OK\n");
            res.push_back(j+1);
            continue;
        }
        // if(pre+suf >= min((int)S[j].size(),(int)T.size())){
        //     res.push_back(j);
        // }
        // else if((int)S[j].size()==(int)T.size() && pre+suf+1==(int)S[j].size()){
        //     debug("Siの文字を1文字変更してTにできるか\n");
        //     res.push_back(j);
        // }
    }
    cout << (int)res.size() << "\n" << flush;
    for(auto r:res){
        cout << r << " ";
    }
    cout << "\n" << flush;
    return 0;
}
