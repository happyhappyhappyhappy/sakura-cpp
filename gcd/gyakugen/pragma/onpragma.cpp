#include<iostream>
#pragma GCC optimize "Ofast" // 03 では無い
// Pragmaで色々設定した場合
// (元:GCD 値渡し＋再帰関数利用する場合のデバッグ確認)
using namespace std;

using ll=long long;

ll extGCD(ll a,ll b,ll &x,ll &y){
    cout << "Start extGCD " <<  
    "a = " << a << " b = " << b << 
    " x = " << x << " &x = " << &x << 
    " y = " << y << " &y = " << &y << "\n";
    if ( b == 0 ){
        x = 1;
        y = 0;
        cout << "Last extGCD " <<
        "x = " << x << " &x = " << &x << 
        " y = " << y << " &y = " << &y << "\n";
        return a;
    }
    ll d;
    d = extGCD(b,a%b,y,x);
    y = y - (a/b)*x;
    cout << "End extGCD " << 
    "d = " << d << " a = " << a << " b = " << b <<
    " x = " << x << " &x = " << &x <<
    " y = " << y << " &y = " << &y << "\n";
    return d;
}

int main(int argc, char const *argv[])
{
    ll x;
    ll y;
    ll d;
    ll invNum=317811; // フィナボッチ28番目
    ll modNum=832040; // フィナボッチ30番目

    cout << "Main Function :" <<
    " invNum = " << invNum <<
    " modNum = " << modNum << 
    " x= " << x << " &x= " << 
    " y= " << y << " &y= " << 
    " d= " << d << "\n";
 
    d = extGCD(invNum,modNum,x,y);
    if(x < 0){
        x = x + modNum;
    }
    cout << "Function Result :" << 
    " x= " << x << " y= " << y << " d= " << d << "\n";
    return 0;
}
/**
 Main Function : invNum = 317811 modNum = 832040 x= 94616911995568 &x=  y= 140724802942512 &y=  d= 0
Start extGCD a = 317811 b = 832040 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 832040 b = 317811 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 317811 b = 196418 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 196418 b = 121393 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 121393 b = 75025 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 75025 b = 46368 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 46368 b = 28657 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 28657 b = 17711 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 17711 b = 10946 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 10946 b = 6765 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 6765 b = 4181 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 4181 b = 2584 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 2584 b = 1597 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 1597 b = 987 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 987 b = 610 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 610 b = 377 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 377 b = 233 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 233 b = 144 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 144 b = 89 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 89 b = 55 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 55 b = 34 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 34 b = 21 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 21 b = 13 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 13 b = 8 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 8 b = 5 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 5 b = 3 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 3 b = 2 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Start extGCD a = 2 b = 1 x = 140724802942512 &x = 0x7ffd0be3f530 y = 94616911995568 &y = 0x7ffd0be3f528
Start extGCD a = 1 b = 0 x = 94616911995568 &x = 0x7ffd0be3f528 y = 140724802942512 &y = 0x7ffd0be3f530
Last extGCD x = 1 &x = 0x7ffd0be3f528 y = 0 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 2 b = 1 x = 0 &x = 0x7ffd0be3f530 y = 1 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 3 b = 2 x = 1 &x = 0x7ffd0be3f528 y = -1 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 5 b = 3 x = -1 &x = 0x7ffd0be3f530 y = 2 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 8 b = 5 x = 2 &x = 0x7ffd0be3f528 y = -3 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 13 b = 8 x = -3 &x = 0x7ffd0be3f530 y = 5 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 21 b = 13 x = 5 &x = 0x7ffd0be3f528 y = -8 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 34 b = 21 x = -8 &x = 0x7ffd0be3f530 y = 13 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 55 b = 34 x = 13 &x = 0x7ffd0be3f528 y = -21 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 89 b = 55 x = -21 &x = 0x7ffd0be3f530 y = 34 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 144 b = 89 x = 34 &x = 0x7ffd0be3f528 y = -55 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 233 b = 144 x = -55 &x = 0x7ffd0be3f530 y = 89 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 377 b = 233 x = 89 &x = 0x7ffd0be3f528 y = -144 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 610 b = 377 x = -144 &x = 0x7ffd0be3f530 y = 233 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 987 b = 610 x = 233 &x = 0x7ffd0be3f528 y = -377 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 1597 b = 987 x = -377 &x = 0x7ffd0be3f530 y = 610 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 2584 b = 1597 x = 610 &x = 0x7ffd0be3f528 y = -987 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 4181 b = 2584 x = -987 &x = 0x7ffd0be3f530 y = 1597 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 6765 b = 4181 x = 1597 &x = 0x7ffd0be3f528 y = -2584 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 10946 b = 6765 x = -2584 &x = 0x7ffd0be3f530 y = 4181 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 17711 b = 10946 x = 4181 &x = 0x7ffd0be3f528 y = -6765 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 28657 b = 17711 x = -6765 &x = 0x7ffd0be3f530 y = 10946 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 46368 b = 28657 x = 10946 &x = 0x7ffd0be3f528 y = -17711 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 75025 b = 46368 x = -17711 &x = 0x7ffd0be3f530 y = 28657 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 121393 b = 75025 x = 28657 &x = 0x7ffd0be3f528 y = -46368 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 196418 b = 121393 x = -46368 &x = 0x7ffd0be3f530 y = 75025 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 317811 b = 196418 x = 75025 &x = 0x7ffd0be3f528 y = -121393 &y = 0x7ffd0be3f530
End extGCD d = 1 a = 832040 b = 317811 x = -121393 &x = 0x7ffd0be3f530 y = 317811 &y = 0x7ffd0be3f528
End extGCD d = 1 a = 317811 b = 832040 x = 317811 &x = 0x7ffd0be3f528 y = -121393 &y = 0x7ffd0be3f530
Function Result : x= 317811 y= -121393 d= 1
 **/
