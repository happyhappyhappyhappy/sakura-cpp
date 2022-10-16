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
    P a,b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    P c,d;
    c.first = b.first-(b.second-a.second);
    c.second=b.second+(b.first-a.first);
    d.first=a.first-(b.second-a.second);
    d.second=a.second+(b.first-a.first);
    printf("C = ( %d , %d )\n",c.first,c.second);
    printf("D = ( %d , %d )\n",d.first,d.second);
    return 0;
}