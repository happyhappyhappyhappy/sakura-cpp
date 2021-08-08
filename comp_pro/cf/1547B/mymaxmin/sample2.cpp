#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase;
    cin >> testcase;
    for(auto j=0;j<testcase;j++){
        int first,second;
        cin >> first >> second;
        cout << "----- " << testcase+1 << " -----\n";
        cout << "1: " <<  first << " 2: " << second << "\n";
        if(mymax(first,second)){
            cout << "Second is large\n" ;
        }
        else
        {
            cout << "First is large\n" ;
        }
         cout << "1: " <<  first << " 2: " << second << "\n";
    }
    return 0;
}
