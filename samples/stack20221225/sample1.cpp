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

// 基本

int main(void){
    stack<int> st;
    vector<int> sendVar={1,3,4,5,3};
    for(int j=0;j<sendVar.size();j++){
        st.push(sendVar[j]);
    }
    while(!st.empty()){
        int out=st.top();
        cout << " " << out ;
        st.pop();
    }
    cout << "\n" << flush;
    return 0;
}
