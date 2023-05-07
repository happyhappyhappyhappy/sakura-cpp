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
const int N=1010;
vector<vector<int>> dp(N,vector<int>(N,0));
template<class X> bool chmax(X &a,X b){
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
            debug(" %d",dp[j][k]);
        }
        debug("\n");
    }
    debug("\n");
}
int lcs(string X,string Y){
    int maxl=0;
    int xl = (int)X.size();
    int yl = (int)Y.size();
    // X,Yだけ同じにしてみる
    X = ' '+X;
    Y = ' '+Y;
    for(int j=1;j<=xl;j=j+1){
        for(int k=1;k<=yl;k=k+1){
            if(X[j]==Y[k]){
                dp[j][k]=dp[j-1][k-1]+1;
            }
            else{
                dp[j][k]=max(dp[j-1][k],dp[j][k-1]);
            }
            chmax(maxl,dp[j][k]);
        }
        showDP(xl,yl);
    }
    return maxl;
}

int main(void){
    initial();
    string s1,s2;
    int n;
    cin >> n;
    while(n--){
        debug("---- %d ----\n",n);
        cin >> s1 >> s2;
        cout << lcs(s1,s2) << "\n" << flush;
    }
    return 0;
}
