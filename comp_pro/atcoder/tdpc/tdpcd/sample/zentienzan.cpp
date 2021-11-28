#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

int main(void){
    initial();
    auto nxt=0.0;
    auto dp=0.0;
    // nxt=12.0 dp=6.0の場合
    nxt = 12.0;
    dp = 6.0;
    cout << "nxt = " << nxt << " : dp = " << dp << "\n" << flush;
    nxt += dp / 6.0;
    cout << "nxt+=dp/6 = " << nxt << "\n" << flush;
    // nxt=12.0 dp=12.0 の場合
    nxt = 12.0;
    dp = 12.0;
    cout << "nxt = " << nxt << " : dp = " << dp << "\n" << flush;
    nxt += dp / 6.0;
    cout << "nxt+=dp / 6 = " << nxt << "\n" << flush;
    // nxt=12.0 dp=12.0 の場合
    nxt = 18.0;
    dp = 6.0;
    cout << "nxt = " << nxt << " : dp = " << dp << "\n" << flush;
    nxt += dp / 6.0;
    cout << "nxt = +dp/6 = " << nxt << "\n" << flush;
    return 0;
}
