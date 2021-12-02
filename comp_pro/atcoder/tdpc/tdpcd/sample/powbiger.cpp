#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using ll=long long;
using db=double;
int main(void){
    using namespace std;

    // db 
    /*
    軸->10^18
    比較->2^?,3^?,5^?
    極端なことを言えば10^18と2^xのxとなる数を求め、
    全部の素数の要素数にすれば良いのだが
    計算量は 64 x 64 x 64=262144
    →googleによれば54
    */
    db tenpow=pow(10,18);
    db twopow=1;
    int counter;
    counter = 1;
    while(true){
        twopow = twopow * 2;
        if(tenpow < twopow){
            cout << "2は " << counter << "で 10^18を追い越す.\n";
            break;
        }
        counter = counter + 1;
    }
    counter = 1;
    db threepow = 1; 
    while(true){
        threepow = threepow * 3;
        if(tenpow < threepow){
            //  この文章を作成するところから作成 2021/10/28
            cout << "3は " << counter << "で 10^18を追い越す.\n";
            break;
        }
        counter = counter + 1;
    }
    // TODO : 5のケースを調べてみる
    /**
    cout << fixed << setprecision(9) << "MIN : " << DBL_MIN << 
    " MAX : " << DBL_MAX << "\n";
    **/
   return 0;
}