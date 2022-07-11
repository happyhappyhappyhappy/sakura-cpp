#include<bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
const long long INF=1LL<<60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int N;
    cin >> N;
    vector<long long> H(N);
    vector<long long> S(N);
    for(int j=0;j<N;j++){
        cin >> H[j] >> S[j];
    }
    long long top=INF;
    long long down=0;
    while(abs(top-down)>1){
        long long mid=(top+down)/2;
        // TODO: ここから
    }
    return 0;
}
