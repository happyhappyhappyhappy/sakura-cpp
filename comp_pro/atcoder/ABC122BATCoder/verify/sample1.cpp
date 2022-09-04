#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

int main(void){
    string S;
    cin >> S;
    int length = S.length();
    for(int ie=0;ie<length;ie=ie+1){
        for(int j=ie;j<length;j=j+1){
            for(int k=ie;k<=j;k=k+1){
                cout << S[k];
            }
            cout << "\n" << flush;
        }
    }
    return 0;
}