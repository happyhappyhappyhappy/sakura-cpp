#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
int main(void){

    // db 
    /*
    TODO: 展望
    軸->10^18
    比較->2^?,3^?,5^?
    極端なことを言えば10^18と2^xのxとなる数を求め、
    全部の素数の要素数にすれば良いのだが
    計算量は 64 x 64 x 64=262144
    →googleによれば54
    */
    cout << fixed << setprecision(9) << "MIN : " << DBL_MIN << 
    " MAX : " << DBL_MAX << "\n";
    return 0;
}