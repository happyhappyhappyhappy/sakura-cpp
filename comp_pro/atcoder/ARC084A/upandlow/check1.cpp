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
    posA = lower_bound(AC.begin(),AC.end(),key)-AC.begin();
    posC = upper_bound(AC.begin(),AC.end(),key)-AC.begin();
    int posC2 = N-posC;
    cout << "Aに使える石は0から " << posA << " まで\n" << flush;
    for(int j=0;j<posA;j++){
        cout << AC[j] << " ";
    }
    cout << "\n" << flush;
    cout << "Cに使える石は " << posC << " から最後まで\n" << flush;
    for(int j=posC;j<AC.size();j++){
        cout << AC[j] << " ";
    }
    cout << "\n" << flush;
    cout << "使える石の個数 posC2 : " << posC2 << "\n" << flush;
    return 0;
}