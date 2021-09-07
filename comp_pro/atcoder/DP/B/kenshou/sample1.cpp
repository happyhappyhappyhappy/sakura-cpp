#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}
int main(void)
{
    initial();
    ll N,K;
    cin >> N >> K ;
    cout << N << "\t" << K << "\n";
    return 0;
}
