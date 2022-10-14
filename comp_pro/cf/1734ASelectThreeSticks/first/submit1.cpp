#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class X> bool inline chmin(X &min_d,X value){if(value < min_d){min_d=value;return true;}else{return false;}}   
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
ll l_MAX=1LL<<60;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll solver(int enumcase,vector<ll> &A){
    ll answer=l_MAX;
    sort(A.begin(),A.end());
    for(int j=0;j+2<enumcase;j=j+1){
        ll subanswer;
        subanswer=A[j+2]-A[j];
        chmin(answer,subanswer);
    }
    return answer;
}

int main(void){
    initial();
    int testcase;
    cin >> testcase;
    while(testcase--){
        int enumcase;
        cin >> enumcase;
        vector<ll> A(enumcase);
        for(int j=0;j<enumcase;j=j+1){
            cin >> A[j];
        }
        cout << solver(enumcase,A) << "\n" << flush;
    }
    return 0;
}
