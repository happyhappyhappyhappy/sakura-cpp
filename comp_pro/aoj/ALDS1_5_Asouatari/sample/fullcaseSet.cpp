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
    int a_count;
    cin >> a_count;
    vector<int> A(a_count);
    for(int j=0;j<a_count;j=j+1){
        cin >> A[j];
    }
    // 今のうちに全部セットするという技
    unordered_set<int> allSum;
    for(int bit=0;bit<(1<<a_count);bit=bit+1){
        int inQ=0;
        for(int j=0;j<a_count;j++){
            if((bit & (1<<j))!=0){
                inQ=inQ+A[j];
            }
        }
        allSum.insert(inQ);
    }
    int qs;
    cin >> qs;
    vector<int> Q(qs);
    for(int j=0;j<qs;j=j+1){
        cin >> Q[j];
    }
    for(int j=0;j < qs;j=j+1){
        int ex_count;
        ex_count=allSum.count(Q[j]);
        if(ex_count==1){
            cout << "yes\n" << flush;
         }
        else{
            cout << "no\n" << flush;
        }
    }
    return 0;
}