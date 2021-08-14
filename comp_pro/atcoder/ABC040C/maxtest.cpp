#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc, char const *argv[])
{
    ll LEFT=1LL << 60;
    ll RIGHT=1LL >> 60;
    cout << "LEFT\t" << LEFT << "\n";
    cout << "RIGHT\t" << RIGHT << "\n";
    return 0;
}
