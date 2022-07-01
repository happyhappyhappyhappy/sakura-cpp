#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

ll lower_bound2(vector<ll> &X,ll key){
    int left,right;
    // TODO : ここから
    right = X.size();
}

ll solver(int N,vector<ll> &U,vector<ll> &M,vector<ll> &B){
    ll result=0;
    sort(U.begin(),U.end());
    sort(M.begin(),M.end());
    sort(B.begin(),B.end());
    for(int j=0;j<M.size();j++){
        int u_able;
        int b_able;
        u_able=lower_bound2(U,M[j]);
        b_able=upper_bound2(B,M[j]);
        result = u_able*b_able+result;
    }
    return result;
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int N;
    cin >> N;
    vector<ll> A_U(N);
    vector<ll> B_M(N);
    vector<ll> C_B(N);
    for(auto &x:A_U){
        cin >> x;
    }
    for(auto &x:B_M){
        cin >> x;
    }
    for(auto &x:C_B){
        cin >> X;
    }
    cout << solver(N,A_U,B_M,C_B) << endl;
    return 0;
}
