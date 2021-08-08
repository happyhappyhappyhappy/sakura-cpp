#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

bool mymin(int &base,int &check)
{
    bool result = false;
    if(base > check){
        base = check;
        return true;
    }
    return result;
}

bool mymax(int &base,int &check)
{
    bool result = false;
    if(base < check){
        base = check;
        return true;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    size_t t = sizeof('z');
    cout << "size_t: " << t << "\n";
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string testStr;
    cin >> testStr;
    size_t t1 = testStr.find('a');
    if(t1 == string::npos){
        cout << "Not Find!! a\n";
        return 10;
    }
    // cout << "testStr.find() :" << t1 << "\n";
    return 0;
}
