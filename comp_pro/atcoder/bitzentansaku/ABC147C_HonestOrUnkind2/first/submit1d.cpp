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
vector<vector<int>> HONEST; // 発言時正直テーブル
vector<vector<int>> LIAR; // 発言時うそつきテーブル
int N; // 発言者数

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
/**
void showHorL(void){
    for(int j=0;j<N;j=j+1){
        debug("%3d 氏の発言\n",j);
        int h_say=(int)HONEST[j].size();
        int l_say=(int)LIAR[j].size();
        debug("正直者 : ");
        if(h_say == 0){
            debug(" 不在 \n");
        }else{
            for(int k=0;k<h_say;k=k+1){
                debug(" %3d ",HONEST[j][k]);
            }
            debug("\n");
        }
        debug("うそつき : ");
        if(l_say == 0){
            debug(" 不在 \n");
        }else{
            for(int k=0;k<l_say;k=k+1){
                debug(" %3d ",LIAR[j][k]);
            }
            debug("\n");
        }
    }
}
**/
/**
void showBit(int &X){
    debug("----");
    for(int S=0;S<N;S=S+1){
        int F=(X>>S)&1;
        debug("%3d",F);
    }
    debug("----\n");
}
**/

int solver(void){
    int res=0;
//    showHorL();
    for(int B=1;B<(1<<N);B=B+1){ // B:Bit列
        bool ok=true;
        int total=0;
//        showBit(B);
        for(int S=0;S<N;S=S+1){ // S:Scale桁確認
            int H_FL = (B>>S) & 1;// 正直者フラグ
            if(H_FL==1){
                total=total+1;
                // 正直者検索
                for(auto &m:HONEST[S]){
                    int honeQ=(B >> m) & 1;
                    if(honeQ==0){
                        debug("%3dが言う正直者->%3d 今の仮定では正直者ではありません。矛盾\n",S,m);
                        ok=false;
                    }
                }
                // ウソつき検索
                for(auto &m:LIAR[S]){
                    int liarQ=(B>>m)&1;
                    if(liarQ==1){// 実は正直だった
                        debug("%3dが言う、うそつき->%3d 今の仮定ではうそつきではありません。矛盾\n",S,m);
                        ok=false;
                    }
                }
            }
        }
        if(ok){
            debug("この仮定においては矛盾していません\n");
            chmax(res,total);
        }
    }
    return res;
}

int main(void){
    initial();
// データ挿入
    cin >> N;
    for(int j=0;j<N;j=j+1){
        vector<int> honest_list;
        vector<int> liar_list;
        int said;
        cin >> said;
        for(int k=0;k<said;k=k+1){
            int who,cont;
            cin >> who >> cont;
            if(cont == 1){
                honest_list.push_back(who-1); // 0-index
            }
            else{
                liar_list.push_back(who-1);
            }
        }
        debug("%3d のデータ入力\n",j);
        HONEST.push_back(honest_list);
        LIAR.push_back(liar_list);
    }
    cout << solver() << "\n" << flush;
    return 0;
}
