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
static string NO="no";
static string YES="yes";

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool solver(vector<int> &A,int Q){
    int asize = A.size();
    bool ansflug=false;
    for(int bit=0;bit < (1<<asize);bit=bit+1){
        int inQ=0;
        for(int pos=0;pos<asize;pos=pos+1){
            if((bit & (1<<pos)) != 0){
                inQ = inQ + A[pos];
            }
        }
        if(inQ == Q){
            ansflug=true;
            break;
        }
    }
    return ansflug;
}

int main(void){
    initial();
    int n;
    cin >> n;
    vector<int> A(n);
    for(int j=0;j<n;j=j+1){
        cin >> A[j];
    }
    int q;
    cin >> q;
    vector<int> m(q);
    for(int j=0;j<q;j=j+1){
        cin >> m[j];
    }
    for(int j=0;j<q;j=j+1){
        if(solver(A,m[j])){
            cout << YES << "\n" << flush;
        }
        else{
            cout << NO << "\n" << flush;
        }
    }

    return 0;
}
