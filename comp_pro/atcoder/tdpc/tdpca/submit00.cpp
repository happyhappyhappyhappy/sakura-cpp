#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll ALLN=110;
// ll ALLPT = ALLN*110;
vector<ll> PT(ALLN); 
// vector<ll> DP(ALLN,ALLPT);


void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);    
}

int main(void){
    initial();
    ll n;
    cin >> n;
   // TODO:ここにコードがある
    for(ll &e:PT){
        cin >> e;
    }
    for(ll j=0;j<n;j=j+1){
        cout << PT[j] << " ";
    }
    cout << "\n";
    return 0;
}