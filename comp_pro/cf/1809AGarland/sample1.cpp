#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

int main(void){
    vector<int> B(10,0);
    string instr;
    cin >> instr;
    for(int j=0;j<(int)instr.size();j=j+1){
        char x = instr.at(j);
        int pos = x - '0';
        B[pos]=B[pos]+1;
    }
    for(int j=0;j<10;j=j+1){
        printf("B[%2d] -> %2d\n",j,B[j]);
    }
    return 0;
}
