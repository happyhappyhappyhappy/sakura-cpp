#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

void shiftshiftCheck(int j){
    int result;
    result = 1<<j;
    cout << j << " : " << result << "\n" << flush;
}

int main(void){
    for(int ie=1;ie < 32 ;ie=ie+1){
        shiftshiftCheck(ie);
    }
    return 0;
}

