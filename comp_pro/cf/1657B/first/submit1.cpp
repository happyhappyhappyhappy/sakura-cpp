#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
// ボツ test2でエラーが出る
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll solver(int n,ll B,ll x,ll y){
    ll result=0;
    /**
    COUT(x);
    COUT(y);
    **/
    vector<ll> a(n+1);
    a[0] = 0;
    for(ll j=0;j<=n;j++){
        if(a[j]+x <= B){
            a[j+1] = a[j] + x;
        }
        else{
            a[j+1] = a[j] - y;
        }
    }
    for(int j=0;j<=n;j=j+1){
        result = result + a[j];
    }
    return result;
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int j=0;j<testcase;j++){
        ll n;
        ll B,x,y;
        ll answer;
        cin >> n >> B >> x >> y;
        answer = solver(n,B,x,y);
        cout << answer << "\n" << flush;
    }
    return 0;
}
