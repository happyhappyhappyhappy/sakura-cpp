#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)

int main(void){
    string baseStr;
    string checkChar;
    cin >> baseStr;
    cin >> checkChar;
    auto x = baseStr.find(checkChar[0]);
    if(x == string::npos)
    {
        cout << baseStr << "に" 
        << checkChar << "は見つからなかった\n" << flush;
    }
    else
    {
        cout << "結果:" << x << "\n" << flush;
    }

    return 0;
}