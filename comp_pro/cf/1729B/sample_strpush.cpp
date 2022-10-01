#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

// 目的 空の文字列へstring.push_back(文字)すれば追加できるか
// OK

int main(void){
    string baseStr="";
    baseStr.push_back('y');
    baseStr.push_back('a');
    baseStr.push_back('m');
    baseStr.push_back('a');
    cout << baseStr << "\n" << flush;
    return 0;
}