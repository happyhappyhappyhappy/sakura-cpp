#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

int main(void){
    ll key;
    cin >> key;
    int N;
    cin >> N;
    vector<ll> AC(N);
    for(ll &x:AC){
        cin >> x;
    }
    sort(AC.begin(),AC.end());
    // チェック
    /**
    for(int j=0;j<N;j++){
        cout << AC[j] << " ";
    }
    cout << "\n" << flush;
    **/
    int posA,posC;
    posA = upper_bound(AC.begin(),AC.end(),key)-AC.begin();
    posC = lower_bound(AC.begin(),AC.end(),key)-AC.begin();
    cout << "Aに使える石は " << posA << " まで\n" << flush;
    cout << "Cに使える石は " << posC << " から\n" << flush;
    return 0;
}