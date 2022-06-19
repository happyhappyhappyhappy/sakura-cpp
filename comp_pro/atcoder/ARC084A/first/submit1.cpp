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
    int SIZE=A.size();
    for(int j=0;j<SIZE;j++){
        cout << A[j] << " ";
    }
    cout << endl;
    for(int j=0;j<SIZE;j++){
        cout << B[j] << " ";
    }
    cout << endl;
    for(int j=0;j<SIZE;j++){
        cout << C[j] << " ";
    }
    cout << endl;
    return result;
}

int main(void){
    initial();
    int N=0;
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

