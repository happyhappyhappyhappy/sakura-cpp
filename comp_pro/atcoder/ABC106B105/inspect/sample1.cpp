#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

void solver(int &N,vector<int> &X){
    for(int ie=1;ie<=int(sqrt(N));ie=ie+1){
        if(N%ie==0){
            X.push_back(ie);
            if(ie*ie!=N){
                X.push_back(N/ie);
            }
        }
    }
    sort(X.begin(),X.end());
}

int main(void){
    int N;
    cin >> N;
    vector<int> X;
    solver(N,X);
    for(int ie=0;ie<int(X.size());ie=ie+1){
        cout << X[ie] << " ";
    }
    cout << "\n" << flush;
    return 0;
}