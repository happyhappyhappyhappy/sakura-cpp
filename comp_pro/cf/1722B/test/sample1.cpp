#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

int main(void){
    string X;
    cin >> X;
    cout << "変更前: " << X << "\n" << flush;
    // アルゴリズムライブラリなのでstdを省略できず
    std::replace(X.begin(),X.end(),'A','Z');
    cout << "変更後: " << X << "\n" << flush;
    return 0;
}