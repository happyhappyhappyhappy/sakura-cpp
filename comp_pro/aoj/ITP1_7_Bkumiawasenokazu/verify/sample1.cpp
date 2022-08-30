#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

int main(void){

    int MAX=9;
    int FORMAX=MAX+1;
    for(int j=1;j<FORMAX;j++){
        for(int k=j+1;k<FORMAX;k++){
            for(int m=k+1;m<FORMAX;m++){
                cout << j << "," << k << "," << m << "\n" << flush;
            }
        }
    }
    return 0;
}