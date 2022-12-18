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

    vector<int> v={1,3,5,7,9};
    int sum=0;
    do{
        for(auto &x:v){
            cout << " " << x ;
        }
        cout << endl;
        sum = sum+1;
    }
    while(next_permutation(v.begin(),v.end()));
    cout << "合計は " << sum << "です" << endl;
    return 0;
}
