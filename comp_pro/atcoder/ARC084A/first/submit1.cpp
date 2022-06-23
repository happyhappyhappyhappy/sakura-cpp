#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll solver(vector<ll> &A,vector<ll> &B,vector<ll> &C){
    ll result = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    ll SIZE=A.size();
    for(ll j=0;j<SIZE;j++){
        ll canA=0; // Aに使える物
        ll canC=0; // Cに使える物
        ll keyLarge=B[j];
        canA = lower_bound(A.begin(),A.end(),keyLarge)-A.begin();
        // keyLarge以上(keyLarge含む)の物を使用しない。
        canC = SIZE-(upper_bound(C.begin(),C.end(),keyLarge)-C.begin());
        // keyLarge以下(keyLarge含む)の物は使用しない
        // keyLarge以上(keyLarge含まない)の物だけ使用する
        result = result + canA*canC;
    }
    return result;
}

int main(void){
    initial();
    ll N=0;
    cin >> N;
    vector<ll> A(N); // 上の段
    vector<ll> B(N); // 中央
    vector<ll> C(N); // 下の段
    for(auto &x:A){
        cin >> x;
    }
    for(auto &x:B){
        cin >> x;
    }
    for(auto &x:C){
        cin >> x;
    }
    cout << solver(A,B,C) << "\n" << flush;
    return 0;
}

