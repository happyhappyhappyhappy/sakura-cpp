#include<iostream>
// GCD 値渡し＋再帰関数利用する場合のデバッグ確認
using namespace std;

using ll=long long;

ll extGCD(ll a,ll b,ll &x,ll &y){
    cout << "Start extGCD " <<  
    "a = " << a << " b = " <<
    " x = " << x << " &x = " << &x << 
    "y = " << y << " &y = " << &y << endl;
    if ( b == 0 ){
        cout << " Last extGCD " <<
        "x = " << x << " &x = " << &x << 
        " y = " << y << " &y = " << &y << endl;
    }
    ll d;
    cout << "End extGCD " << 
    "d = " << d << "a = " << a << " b = " << b <<
    " x = " << x << " &x = " << &x <<
    " y = " << y << " &y = " << &y << endl;
    return d;
}

