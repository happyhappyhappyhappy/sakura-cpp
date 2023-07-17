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
template<class XXX> void chmax(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
// グローバル変数
vector<vector<int>> HONEST;
vector<vector<int>> LIAR;
int N;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showHL(void){
    for(int j=0;j<N;j=j+1){
        debug("--- 発言者 %d の内容 ---\n",j);
        debug("正直 : ");
        int HSIZE = (int)HONEST[j].size();
        if(HSIZE==0){
            debug(" 不在 \n");
        }
        else{
            for(int k=0;k<HSIZE;k=k+1){
                debug(" %d ",HONEST[j][k]);
            }
            debug("\n");
        }
        debug("うそつき :");
        int LSIZE=(int)LIAR[j].size();
        if(LSIZE == 0){
            debug(" 不在\n");
        }
        else{
            for(int k=0;k<LSIZE;k=k+1){
                debug(" %d ",LIAR[j][k]);
            }
            debug("\n");
        }
    }
}
int dfs(int per,vector<int> &H,vector<int> &L){
    if(per == N){
        debug("-----到着-----\n");
        debug("正直 : ");
        int hsize=(int)H.size();
        if(hsize ==0){
            debug(" 不在\n");
        }
        else{
            for(int j=0;j<hsize;j=j+1){
                debug(" %d ",H[j]);
            }
            debug("\n");
        }
        debug("ウソつき : ");
        int lsize=(int)L.size();
        if(lsize ==0){
            debug(" 不在\n");
        }
        else{
            for(int j=0;j<hsize;j=j+1){
                debug(" %d ",L[j]);
            }
            debug("\n");
        }
        return hsize;
    }
    else{
        int ish,isl;
        vector<int> H2=H;
        H2.push_back(per);
        ish = dfs(per+1,H2,L);
        vector<int> L2=L;
        L2.push_back(per);
        isl = dfs(per+1,H,L2);
        if(ish < isl){
            return isl;
        }
        else
        {
        return ish;
        }
    }
}
int solver(void){
    int ans=0;
    showHL();
    vector<int> liar_list;
    vector<int> honest_list;
    ans = dfs(0,honest_list,liar_list);
    return ans;
}
int main(void){
    initial();
    cin >> N;
    for(int j=0;j<N;j=j+1){
        int COM;
        cin >> COM;
        vector<int> honest_list;
        vector<int> liar_list;
        for(int k=0;k<COM;k=k+1){
            int who;
            int pos;
            cin >> who >> pos;
            if(pos==1){
                honest_list.push_back(who-1);
            }
            else{
                liar_list.push_back(who-1);
            }
        }
        HONEST.push_back(honest_list);
        LIAR.push_back(liar_list);
    }
    cout << solver() << "\n" << flush;
    return 0;
}
