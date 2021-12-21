#include<bits/stdc++.h>
#include<cmath>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

int main(void){
    int rui2,rui3,rui5;
    double DiceMax=pow(6.0,100.0);
    double baisuMax=pow(10.0,18.0);
    // rui2 = int(log(logDiceMax/log(2.0))+1;
    // rui3 = int()
    cout << fixed << setprecision(10);
    cout << "サイコロ最大\t" << DiceMax << "\n" << flush;
    cout << "倍数最大\t" << baisuMax << "\n" << flush;
    return 0;
}

// サイコロ最大    653318623500070897423596169561540920217390783243900597935846601233315745759232.0000000000
// 倍数最大        1000000000000000000.0000000000