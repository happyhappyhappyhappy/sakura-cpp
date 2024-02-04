#include<bits/stdc++.h>
#ifdef LOCAL
#include"/wrk/sakura-cpp/comp_pro/debug.h"
#include"/wrk/sakura-cpp/comp_pro/t_debug.h"
#include"/wrk/sakura-cpp/lib/dump.hpp"
#else
#define debug(...) 42
#define debug2(...) 42
#define debugt(...) 42
#define to_string(...) 42
#define debug_out(...) 42
#endif
using namespace std;
using ll=long long;
const double pi = 3.141592653589793238;
const int yamaMAX_INT = 1 << 29;
const ll yamaMAX_LL = 1LL << 60;
int N,L,R;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int needX(int& A){
    int X=L;
    for(int Xa=L;Xa<=R;Xa=Xa+1){
        bool flug=true;
        for(int Y=L;Y<=R;Y=Y+1){
            int first = abs(Xa-A);
            int second = abs(Y-A);
            if(first > second){
                flug=false;
                break;
            }
        }
        if(flug){
            X=Xa;
            break;
        }
    }
    return X;
}
void solver(vector<int>& A,vector<int>& X){
    for(int j=0;j<N;j=j+1){
        X[j]=needX(A[j]);
    }
    return;
}
int main(void){
    initial();
    cin >> N >> L >> R;
    vector<int> A(N,0);
    for(int j=0;j<N;j=j+1){
        cin >> A[j];
    }
    vector<int> X(N,0);
    solver(A,X);
    for(int j=0;j<N;j=j+1){
        if(j!=0){
            cout << " ";
        }
        cout << X[j];
    }
    cout << endl;
    return 0;
}
