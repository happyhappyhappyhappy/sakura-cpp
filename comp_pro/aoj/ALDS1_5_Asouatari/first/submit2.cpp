#include<bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

bool solver(vector<int> &A,int Q){
    int asize = A.size();
    for(int bit=0;bit < (1<<asize);bit=bit+1){
        int inQ=0;
        for(int pos=0;pos<asize;pos=pos+1){
            if((bit & (1<<pos)) != 0){
                inQ = inQ + A[pos];
            }
        }
        if(inQ == Q){
            return true;
        }
    }
    return false;
}

int main(void){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int j=0;j<n;j=j+1){
        cin >> A[j];
    }
    int q;
    cin >> q;
    vector<int> Q(q);
    for(int j=0;j<q;j++){
        cin >> Q[j];
    }
    for(int j=0;j<q;j++){
        if(solver(A,Q[j])){
            cout << "yes\n" << flush;
        }
        else{
            cout << "no\n" << flush;
        }
    }
    return 0;
}
