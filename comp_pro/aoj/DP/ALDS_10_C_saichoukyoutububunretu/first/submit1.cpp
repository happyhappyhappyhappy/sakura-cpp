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
const ll yamaMAX_LL = 1LL << 58;
const int NMAX=1010;
vector<vector<int>> dp(NMAX,vector<int>(NMAX,0));
template<class XXX> bool chmax(XXX &a,XXX &b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void showDP(int X,int Y){
    for(int j=0;j<=X;j=j+1){
        for(int k=0;k<=Y;k=k+1){
            debug(" %3d",dp[j][k]);
        }
        debug("\n");
    }
    debug("\n");
}

int main(void){
    initial();
    int n;
    cin >> n;
    while(n--){
        debug("----- Problem %d-----\n",n);
        string X;
        string Y;
        cin >> X;
        cin >> Y;
        int xs=(int)X.size();
        int ys=(int)Y.size();
        X = ' '+X;
        Y = ' '+Y;
        int ans=0;
        for(int j=1;j<=xs;j=j+1){
            for(int k=1;k<=ys;k=k+1){
                if(X[j]==Y[k]){
                    debug("Xの %d 番目と Yの %d 番目は同じ「%c」です\n"
                    ,j,k,X[j]);
                    dp[j][k]=dp[j-1][k-1]+1;
                    debugt(dp[j][k]);
                }
                else{
                    dp[j][k]=max(dp[j-1][k],dp[j][k-1]);
                }
                chmax(ans,dp[j][k]);
            }
            showDP(xs,ys);
        }
        cout << ans << "\n" << flush;
    }
    return 0;
}
