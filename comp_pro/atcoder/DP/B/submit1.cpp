#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
    long long N,K;
    cin >> N >> K;
    const long long LIMITSTR = 1LL << 31;
    const long long LIMITAREA = 200000;
    const long long LIMITMAX = 1LL<<61;
// limitmax これでは小さいのでは？33000位？
// 解答例を見て再設定せいぜい31へ、型もlong long にしてみる
    vector<long long> H(LIMITAREA);
    vector<long long> DP(LIMITAREA);
    for(long long j=0;j<LIMITAREA;j=j+1){
        H[j] = LIMITMAX;
        DP[j] = LIMITMAX;
    }
    for(long long j=0;j<N;j=j+1){
        cin >> H[j];
    }
    // for(auto &e:h){
    //     cout << e << " ";
    // }
    // cout << "\n";
    DP[0] = 0;
    for(long long j=0;j < N;j=j+1){
        for(long long m=1; m < K+1 ; m = m + 1){
           long long frompos,topos;
           frompos = j;
           topos = j+m;
           minchange(DP[topos],DP[frompos]+abs(H[topos]-H[frompos]));
        }
    }
    cout << DP[N-1] << "\n";
    return 0;
}
