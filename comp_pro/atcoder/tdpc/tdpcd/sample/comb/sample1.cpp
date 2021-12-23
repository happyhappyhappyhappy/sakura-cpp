#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int comb(int n,int k){
    int result = 1;
    int bunbo1 = 1;
    int bunbo2 = 1;
    int bunsi = 1;
    for(int ii = 1 ; ii <= n ; ii=ii+1){
        bunsi = bunsi * ii;
    }
    for(int ii = 1 ; ii <= k ; ii=ii+1){
        bunbo1 = bunbo1 * ii;
    }
    for(int ii=1 ; ii <= n-k ; ii = ii+1){
        bunbo2 = bunbo2 * ii;
    }
    result = bunsi / (bunbo1*bunbo2);
    return result;
}

int main(void){
    initial();
    int n,k;
    cin >> n >> k;
    cout << "nCk is " << comb(n,k) << "\n" << flush;
    return 0;
}
