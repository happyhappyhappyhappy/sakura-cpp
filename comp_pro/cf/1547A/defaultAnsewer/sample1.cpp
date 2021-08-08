#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

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
    return result ;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase;
    cin >> testcase;
    for(int test=0;test<testcase;test=test+1){
        cout << resolve() << "\n";
    }
    return 0;
}
