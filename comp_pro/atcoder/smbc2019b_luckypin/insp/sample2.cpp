#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define STREND std::string::npos

int main(void){
    string N="1234";
    int x=1;
    string x_c=to_string(x);
    if(N.find(x_c)==STREND){
        cout << N << " に "<< x_c << "は存在しません\n";
    }
    else{
        cout << N << " に "<< x_c << "は存在します\n";
    }
    return 0;
}