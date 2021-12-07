#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

int main(void){
    initial();
    ll N,D;
    cin >> N >> D; // N => サイコロを振る回数,D => 振った結果この倍数か
    int pf[3]={0,0,0};
    int div[3] = {2,3,5};
    for(int j=0;j<3;j=j+1){
        while(D % div[j] == 0){
            pf[j]=pf[j]+1;
            D = D / div[j];
        }
    }
    if( D != 1 ){
        cout << 0.0 << "\n" << fflush;
    }
    else{
        cout << pf[0] << ":" << pf[1] 
        << ":" << pf[2] << "\n" << fflush; 
    }
    return 0;
}
