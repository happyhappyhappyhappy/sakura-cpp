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
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
vector<vector<int>> honests;
vector<vector<int>> liars;
int N;
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showHLFigure(void){
    for(int j=0;j<N;j=j+1){
        debug("%3d さんの発言:\n",j);
        debug("\t正直者 : ");
        if(honests[j].size()==0){
            debug("いません");
        }
        else{
            for(int k=0;k<(int)honests[j].size();k=k+1){
                debug("%4d",honests[j][k]);
            }
        }
        debug("\n");
        debug("\tうそつき : ");
        if(liars[j].size()==0){
            debug("いません");
        }
        else{
            for(int k=0;k<(int)liars[j].size();k=k+1){
                debug("%4d",liars[j][k]);
            }
        }
        debug("\n");
    }
}
void showMusk(int &X){
    debug("------ %4dの状態 ------\n",X);
    vector<int> honestL(N,-1);
    vector<int> liarL(N,-1);
    for(int j=0;j<N;j=j+1){
        int yorn=(X>>j) & 1;
        if(yorn==1){
            honestL[j]=1;
        }
        else{
            liarL[j] = 1;
        }
    }
    debug("正直者チェック->");
    for(int j=0;j<N;j=j+1){
        debug(" %3d",honestL[j]);
    }
    debug("\n");
        debug("うそつきチェック->");
    for(int j=0;j<N;j=j+1){
        debug(" %3d",liarL[j]);
    }
    debug("\n");
}
void showMask2(int &mask){
    debug("----- ");
    for(int j=0;j<N;j=j+1){
        int x=0;
        x = (mask>>j)&1;
        debug(" %d",x);
    }
    debug("-----\n");
}
int solver(void){
    int res=0;
    for(int mask=0;mask<(1<<N);mask=mask+1){
        bool ok=true;
        int total=0;
        showMask2(mask);
        for(int j=0;j<N;j=j+1){
            if(((mask>>j) & 1)==1){
                debug("%3dが正しいと仮定\n",j);
                total=total+1;
                for(auto &honest:honests[j]){
                    if(((mask>>honest)&1)==0){
                        debug("%3d情報で正直の「マスクと初期データが」矛盾する\n",honest);
                        ok=false;
                    }
                }
                for(auto &liar:liars[j]){
                    if(((mask>>liar)&1)==1){
                        ok=false;
                        debug("%3d情報でウソつきの「マスクと初期データが」矛盾する\n",liar);
                    }
                }
            }
        }
    if(ok==true){
        debug("%3d -> OK\n",mask);
        chmax(res,total);
        }
    }
    return res;
}
int main(void){
    initial();
    cin >> N;
    for(int j=0;j<N;j=j+1){
        vector<int> liarL;
        vector<int> honestL;
        int S;// 発言数
        cin >> S;
        for(int k=0;k<S;k=k+1){
            int x=-1;
            int y=-1;
            cin >> x >> y;
            if(y==1){
                honestL.push_back(x-1);
            }
            else{
                liarL.push_back(x-1);
            }
        }
        honests.push_back(honestL);
        liars.push_back(liarL);
    }
    showHLFigure();
    cout << solver() << "\n" << flush;
    return 0;
}
