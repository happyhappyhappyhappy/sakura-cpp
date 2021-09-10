#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

template<class XXX> inline bool minchange(XXX &a,XXX b){
    if( b < a){
        a = b;
        return true;
    }
    return false;
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}

int main(void){
    initial();
    int N,K;
    cin >> N >> K;
    const int LIMITAREA = 200000;
    const int LIMITMAX = 1<<15;
    vector<int> H(LIMITAREA);
    vector<int> DP(LIMITAREA);
    for(int j=0;j<LIMITAREA;j=j+1){
        H[j] = LIMITMAX;
        DP[j] = LIMITMAX;
    }
    for(for j=0;j<N;j=j+1){
        cin >> h[j];
    }
    // for(auto &e:h){
    //     cout << e << " ";
    // }
    // cout << "\n";
    dp[0] = 0;
    for(int j=0;j < N;j=j+1){
        for(int m=0; m < K ; m = m + 1){
           int frompos,topos;
           frompos = j;
           topos = j+m+1;
           // 2021/09/11 はここの実装から
        }
    }
}