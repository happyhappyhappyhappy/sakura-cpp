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
    vector<tuple<int,int,int>> T(3);
    T[0] = make_tuple(1,2,3);
    T[1] = make_tuple(2,4,6);
    T[2] = make_tuple(4,16,36);
    int y = get<2>(T[2]);
     cout << y << "\n" << flush ;
    return 0;
}
