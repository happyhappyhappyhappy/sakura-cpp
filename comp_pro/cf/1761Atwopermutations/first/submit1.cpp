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

bool solver(int &n,int &a,int &b){
    // init sample
    if(n==a && a==b){
        return true;
    }
    int diff = n-a-b;
    if(2<=diff){
        return true;
    }
    return false;
}

int main(void){
    initial();
    int testcase;
    cin >> testcase;
    while(testcase--){
        int n,a,b;
        cin >> n >> a >> b;
        if(solver(n,a,b)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
        cout << flush;
    }

    return 0;
}

