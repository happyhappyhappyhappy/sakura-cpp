#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

int main(void){
    string first;
    string second;
    cin >> first;
    cin >> second;
    cout << "文字列1: " << first << "\n" << flush;
    cout << "文字列2: " << second << "\n" << flush;
    int judge=first.compare(second);
    cout << "戻し値: " << judge << "\n" << flush;
    return 0;
}