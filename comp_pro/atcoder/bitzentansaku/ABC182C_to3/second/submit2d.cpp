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
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
void showNum(vector<int> &N){
    int strLeng=int(N.size());
    for(int j=0;j<strLeng;j=j+1){
        debug("%3d  ",N[j]);
    }
    debug("\n");
}
int solver(string &S){
    int ans=yamaMAX_INT;
    int strLeng=int(S.size());
    vector<int> N(strLeng,0);
    for(int j=0;j<strLeng;j=j+1){
        N[j]=S[j]-'0'; // 各桁を整数値にする
    }
    for(int j=((1<<strLeng)-1);j>0;j=j-1){
        int sum=0;
        int scale=0;
        for(int k=0;k<strLeng;k=k+1){
            if(((j>>k)&1)==1){
                debug("%3d 桁目利用\n",k);
                sum=sum+N[k];
                scale=scale+1;
            }
        }
        // debug("%d の時 合計は %d でした\n",j,sum);
        if((sum%3)==0){
            int scaleDiff=strLeng-scale;
            // debug("%d は 3の倍数でした %dをセットします\n",sum,scaleDiff);
            chmin(ans,scaleDiff);
        }
    }
    if(ans==yamaMAX_INT){
        ans=-1;
    }
    return ans;
}
int main(void){
    initial();
    string gNum; // 数値を文字列としてあえて扱う
    cin >> gNum;
    cout << solver(gNum) << "\n" << flush;
    return 0;
}
