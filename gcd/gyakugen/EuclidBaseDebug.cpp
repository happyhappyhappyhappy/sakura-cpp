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
        cout << "swap(u,v)-> u= " << u <<
        " v= " << v << endl;
    }
    cout << " b= " << b <<
    "is false." << endl;
    u = u % m ;
    if(u < 0){
        u = u + m;
    }
    cout << "End Status" <<
    " a= " << a <<
   " b= " << b <<
   " u= " << u <<
   " v= " << v << endl;
    return u;
}

int main(int argc, const char** argv) {
    ll ans;
    ans = modinv(7,5);
    cout << "7's inv: " << ans << " mod 5" <<endl;      
    return 0;
}

/*
Start status: a= 7 b= 5 u= 1 v= 0
 b= 5is true
 t= 1
a=a-t*b ->2
swap(a,b) ->a = 5b = 2
u=u-t*v ->1swap(u,v)-> u= 0 v= 1
 b= 2is true
 t= 2
a=a-t*b ->1
swap(a,b) ->a = 2b = 1
u=u-t*v ->-2swap(u,v)-> u= 1 v= -2
 b= 1is true
 t= 2
a=a-t*b ->0
swap(a,b) ->a = 1b = 0
u=u-t*v ->5swap(u,v)-> u= -2 v= 5
 b= 0is false.
End Status a= 1 b= 0 u= 3 v= 5
7's inv: 3 mod 5
*/