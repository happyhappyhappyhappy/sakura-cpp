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
using POS=pair<int,int>;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 58;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int H,W;
    vector<int> even_dh={-1,0,1,1,0,-1};
    vector<int> even_dw={0,1,0,-1,-1,-1};
    vector<int> odd_dh={-1,0,1,1,0,-1};
    vector<int> odd_dw={1,1,1,0,-1,0};

    cin >> W >> H;
    vector<vector<int>> G(H+2,vector<int>(W+2,0));
    vector<vector<int>> V(H+2,vector<int>(W+2,0));
    for(int j=1;j<=H;j=j+1){
        for(int k=1;k<=W;k=k+1){
            cin >> G[j][k];
        }
    }
    queue<POS> Q;
    Q.push(make_pair(0,0));
    int answer=0;
    while(Q.empty()==false){
        POS nowpos = Q.front();Q.pop();
        int nowposH = nowpos.first;
        int nowposW = nowpos.second;

        debug("(%d,%d)に入りました\n",nowposH,nowposW);
        vector<int> dh;
        vector<int> dw;
        if(nowposH % 2 == 1){
            dh = odd_dh;
            dw = odd_dw;
        }
        else{
            dh = even_dh;
            dw = even_dw;
        }
        for(int j=0;j<6;j=j+1){
            int ddh = dh[j];
            int ddw = dw[j];
            int nextposH = nowposH+ddh;
            int nextposW = nowposW+ddw;
            debug("\t(%d,%d)について検索します\n",nextposH,nextposW);
            if(nextposH < 0 || nextposW < 0 ||
            H+2 <= nextposH || W+2 <= nextposW){
                debug("\t(%d,%d)は範囲外です\n",nextposH,nextposW);
                continue;
            }
            else{
                if(G[nextposH][nextposW]==1){
                    debug("\t(%d,%d)は建物に入っています→カウント",nextposH,nextposW);
                    answer=answer+1;
                    debug(" %d\n",answer);
                    continue;
                }
                else{
                    if(V[nextposH][nextposW]==1){
                        debug("\t(%d,%d)は訪問済みです\n",nextposH,nextposW);
                        continue;
                    }
                    else{
                        debug("\t\t(%d,%d)をこれから検索します\n",nextposH,nextposW);
                        Q.push(make_pair(nextposH,nextposW));
                        V[nextposH][nextposW]=1;
                    }
                }
            }

        }
    }
    cout << answer << "\n" << flush;
    return 0;
}

