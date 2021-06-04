#include<iostream>
//  拡張ユークリッド互除法の
//  ベースプログラム
//  デバッグ出力付き
using namespace std;
using ll=long long;

ll modinv(ll a,ll m){
    ll b;
    b=m;
    ll u,v;
    u = 1;
    v = 0;
    cout << "Start status:"<< 
    " a= " << a <<
    " b= " << b <<
    " u= " << u <<
    " v= " << v << endl;
    while(b){
        cout << " b= " << b
        << "is true" << endl;
        ll t;
        t = a/b;
        cout << " t= " << t << endl;
        a = a - t * b;
        cout << "a=a-t*b ->" << a << endl;
        swap(a,b);
        cout << "swap(a,b) ->" << 
        "a = " << a <<
        "b = " << b << endl;
        u = u - t*v;
        cout << "u=u-t*v ->" << u;
        swap(u,v);
        

    } 
}