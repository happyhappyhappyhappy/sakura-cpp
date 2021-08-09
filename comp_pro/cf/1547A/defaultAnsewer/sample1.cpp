#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

bool checkNotOver(vector<int> &a,vector<int> &b,vector<int> &f){
    bool result = true;
    // 同じx座標にある場合
    if(a[0] == b[0] && a[0] == f[0]){
        cout << "同じx座標に全部並んでます\n";
        result = false;
        return result;
    }
    if(a[1] == b[1] && a[1] == f[0]){
        cout << "同じy座標に全部並んでいます\n";
        result = false;
        return result;
    }
    return result;
}

int resolve(){
    int result = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a(2);
    vector<int> b(2);
    vector<int> f(2);
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    cin >> f[0] >> f[1];
    result = abs(a[0]-b[0])+abs(a[1]-b[1]);
    if(checkNotOver(a,b,f)){
        cout << "このまま使ってもOK\n" ;
    }
    else{
        cout << "まだ確認することがあります\n";
    }
    return result ;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase;
    cin >> testcase;
    for(int test=0;test<testcase;test=test+1){
        cout << "--- テスト その " << test+1 << " \n";
        cout << resolve() << "\n";
    }
    return 0;
}
