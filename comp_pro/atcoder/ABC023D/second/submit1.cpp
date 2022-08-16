#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
const long long MAX_HIGH=1LLe15;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int N;
    vector<ll> H(N);
    vector<ll> S(N);
    for(int j=0;j<N;j=j+1){
        cin >> H(j) >> S(j);
    }
    cout << solver(N,H,S) << "\n" << flush;
    return 0;
}
