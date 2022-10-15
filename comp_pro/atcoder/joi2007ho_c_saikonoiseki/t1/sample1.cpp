#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x < y){
        x = y;
    }
}
typedef pair<int,int> P;


int main(void){
    int coord_point;
    cin >> coord_point;
    vector<P> Point(coord_point);
    for(int j=0;j<coord_point;j=j+1){
        cin >> Point[j].first >> Point[j].second ;
    }
    return 0;
}