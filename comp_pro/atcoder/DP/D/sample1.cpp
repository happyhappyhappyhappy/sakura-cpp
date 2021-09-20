#include<bits/stdc++.h>
using namespace std;

template<class XXX> inline bool chmin(XXX& x,XXX y){
    if(x>y){
        x = y;
        return true;
    }
    return false;
}
template<class XXX> inline bool chmax(XXX& x,XXX y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << fixed << setprecision(10);    
}