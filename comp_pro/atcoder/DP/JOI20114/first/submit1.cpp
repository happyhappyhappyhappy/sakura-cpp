#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int testcase=1;
    //CodeForceの時はここのコメントを削除 cin >> testcase;
    for(int ii=0;ii<testcase;ii++){
        cout << solve() << "\n" << flush;
    }  
    return 0;
}
