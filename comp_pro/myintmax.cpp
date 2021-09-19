#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
// https://cpprefjp.github.io/reference/climits/int_max.html
int main(void){
    cout << "INT_MAX = " << INT_MAX << "\n";
    cout << "INT64_MAX = " << INT64_MAX << "\n";
    cout << "LONG_LONG_MAX = " << LONG_LONG_MAX << "\n";
}

// atcoderも同じ値になっている
// INT_MAX = 2147483647
// INT64_MAX = 9223372036854775807
// LONG_LONG_MAX = 9223372036854775807