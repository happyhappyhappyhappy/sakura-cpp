#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
// 検証目的 whileを自由にしておいて0になったら抜けるか

int main(void){
    int keta;
    string inspectStr;
    cin >> keta >> inspectStr;
    while(true){
        keta = keta-1;
        char x = inspectStr.at(keta);
        cout << x ;
        if(keta <= 0){
            break;
        }
    }
    cout << "\n" << flush;
    return 0;
}