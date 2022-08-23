#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int N;
    ll M;
    vector<ll> P;
    P.push_back(0);
    cin >> N >> M;
    for(int j=0;j<N;j=j+1){
        ll num;
        cin >> num;
        P.push_back(num);
    }
    vector<ll> D2; // ダーツを二回投げて得られる点数
    for(int j=0;j<P.size();j=j+1){
        
    }

    return 0;
}
