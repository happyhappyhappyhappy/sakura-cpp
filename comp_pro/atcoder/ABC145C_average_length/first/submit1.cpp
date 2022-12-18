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

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

double solver(int &pos,vector<int> &v,
vector<double> &x,vector<double> &y){
    
    return 0.0;
}

int main(void){
    initial();
    int pos;
    cin >> pos;
    vector<int> v(pos,0);
    for(int j=0;j<pos;j=j+1){
        v[j]=j;
    }
    vector<double> x(pos,0),y(pos,0);
    for(int j=0;j<pos;j=j+1){
        int fst,sec;
        cin >> fst >> sec;
        x[j]=(double)fst;
        y[j]=(double)sed;
    }
    double ans = solver(pos,v,x,y);
    cout << setprecision(10) << setiosflags(ios::fixed);
    cout << ans << endl;
    return 0;
}

