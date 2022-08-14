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
ll solver(ll &X){
    ll result=0;
    if(X == 1){
        return 2;
    }
    if(X % 3==0){
        return X/3;
    }
    else{
        return X/3+1;
    }
    return result;
}


int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int j=0;j<testcase;j=j+1){
        ll inputNum;
        cin >> inputNum;
        cout << solver(inputNum) << "\n" << flush;
    }
    return 0;
}
