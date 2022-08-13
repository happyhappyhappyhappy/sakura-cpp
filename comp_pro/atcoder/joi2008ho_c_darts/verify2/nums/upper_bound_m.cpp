#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

int main(void){

    int E;
    int B; // ここの中身をこちょこちょ替える
    cin >> E >> B;
    vector<int> X(E);
    for(int j=0;j<E;j=j+1){
        cin >> X[j];
    }
    int right = X.size();
    int left = -1;
    while(right-left>1){
        int mid = (right+left)*pow(2,-1);
        if(X[mid]){}
    }
    cout << "ポインタ表現: " << *Iter << "\n" << flush;
    cout << "位置表現: " << Iter - X.begin() << "\n" << flush;
    if(Iter==X.begin()){
        cout << "位置表現はX.begin()と同じです\n" << flush;
    }
    else{
        cout << "位置表現はX.begin()と異なります\n" << flush;
    }
    return 0;
}