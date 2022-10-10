#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template <class X> bool chmin(X &a, X b) { if (a > b) {a = b; return true;} return false; }
ll MAX_LENG=(1LL<<60)/2;
// TODO: 52という数値は配列にして何個目か？
int main(void){
    ll testcase;
    cin >> testcase;
    vector<ll> A(testcase);
    for(ll j=0;j<testcase;j=j+1){
        cin >> A[j];
    }
    
    ll min_pos=0;
    ll min_length=MAX_LENG;
    for(int enter_pos=0;enter_pos<=100;enter_pos=enter_pos+1){
        ll totalpos=0;
        for(int pos=0;pos<testcase;pos=pos+1){
            totalpos=totalpos+abs(A[pos]-enter_pos);
        }
        cout << enter_pos << " : " << totalpos << "\n" << flush;
        if(chmin(min_length,totalpos)){
            cout << enter_pos << "で最小値入れ替えが発生しました\n" << flush;
        }
    }
    return 0;
}