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
vector<vector<int>> HONEST; // 発言時正直テーブル
vector<vector<int>> LIAR; // 発言時ウソつきテーブル
int N; // 発言者数

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showHorLS(void){
    int hsize = int(HONEST.size());
    int usize = int(LIAR.size());
    for(int j=0;j<hsize;j=j+1){
        debug("%d :",j);
        for(int k=0;k<int(HONEST[j].size());k=k+1){
            debug(" %3d",HONEST[j][k]);
        }
        debug("\n");
    }
    for(int j=0;j<usize;j=j+1){
        debug("%d :",j);
        for(int k=0;k<int(LIAR[j].size());k=k+1){
            debug(" %3d",LIAR[j][k]);
        }
        debug("\n");
    }
}
void showHorL(void){
    for(int j=0;j<N;j=j+1){
        debug("--%d 氏の発言--\n",j);
        int h_say=int(HONEST[j].size());
        int u_say=int(LIAR[j].size());
        debug("正直者:");
        if(h_say!=0){
            for(int k=0;k<h_say;k=k+1){
                debug(" %3d",HONEST[j][k]);
            }
            debug("\n");
        }
        else{
            debug("不在\n");
        }
        debug("うそつき:");
        if(u_say!=0){
            for(int k=0;k<u_say;k=k+1){
                debug(" %3d",LIAR[j][k]);
            }
            debug("\n");
        }
        else{
            debug("不在\n");
        }
    }
}
int solver(void){
    int ans=0;
    // showHorL();
    for(int b=1;b<(1<<N);b=b+1){
        bool ok=true;
        int total=0;
        for(int s=0;s<N;s=s+1){
            int H_FL = (B>>S) & 1;
            if(H_FL==1){

            }
        }
    }



    return ans;
}
int main(void){
    initial();
    cin >> N;
    for(int j=0;j<N;j=j+1){
        vector<int> honest_list;
        vector<int> liar_list;
        int comment;
        cin >> comment;
        for(int k=0;k<comment;k=k+1){
            int who,h_or_l;
            cin >> who >> h_or_l;
            if(h_or_l == 1){
                honest_list.push_back(who-1);
            }else{
                liar_list.push_back(who-1);
            }
        }
        HONEST.push_back(honest_list);
        LIAR.push_back(liar_list);
    }
    cout << solver() << "\n" << flush;
    return 0;
}
