#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll value;
    value = 1LL << 2;
    cout << "value of 1LL << 2\t" << value << "\n";
    value = 1LL << 3;
    cout << "value of 1LL << 3\t" << value << "\n";
    return 0;
}
