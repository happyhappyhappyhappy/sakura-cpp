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
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> A(N,vector<ll>(M));
    for(ll STD=0;STD<N;STD=STD+1){
        for(ll SNG=0;SNG<M;SNG=SNG+1){
            cin >> A[STD][SNG];
        }
    }
    for(ll STD=0;STD<N;STD=STD+1){
        for(ll SNG=0;SNG<M;SNG=SNG+1){
            cout << A[STD][SNG] << " ";
        }
        cout << "\n" << flush;
    }
    return 0;
}
