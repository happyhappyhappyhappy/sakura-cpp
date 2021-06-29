#include<iostream>
// Pragmaで何にも設定していない場合
// (元:GCD 値渡し＋再帰関数利用する場合のデバッグ確認)
using namespace std;

using ll=long long;

ll extGCD(ll a,ll b,ll &x,ll &y){
    cout << "Start extGCD " <<  
    "a = " << a << " b = " << b << 
    " x = " << x << " &x = " << &x << 
    " y = " << y << " &y = " << &y << endl;
    if ( b == 0 ){
        x = 1;
        y = 0;
        cout << "Last extGCD " <<
        "x = " << x << " &x = " << &x << 
        " y = " << y << " &y = " << &y << endl;
        return a;
    }
    ll d;
    d = extGCD(b,a%b,y,x);
    y = y - (a/b)*x;
    cout << "End extGCD " << 
    "d = " << d << " a = " << a << " b = " << b <<
    " x = " << x << " &x = " << &x <<
    " y = " << y << " &y = " << &y << endl;
    return d;
}

int main(int argc, char const *argv[])
{
    ll x;
    ll y;
    ll d;
    ll invNum=7;
    ll modNum=5;

    cout << "Main Function :" <<
    " invNum = " << invNum <<
    " modNum = " << modNum << 
    " x= " << x << " &x= " << 
    " y= " << y << " &y= " << 
    " d= " << d << endl;
 
    d = extGCD(invNum,modNum,x,y);
    if(x < 0){
        x = x + modNum;
    }
    cout << "Function Result :" << 
    " x= " << x << " y= " << y << " d= " << d << endl;
    return 0;
}
/*
Main Function : invNum = 7 modNum = 5 x = 140632707166152 &x =  y = 94478354388928 &y=  d= 140725312661552
Start extGCD a = 7 b = 5 x = 140632707166152 &x = 0x7ffd2a45a710 y = 94478354388928 &y = 0x7ffd2a45a718
Start extGCD a = 5 b = 2 x = 94478354388928 &x = 0x7ffd2a45a718 y = 140632707166152 &y = 0x7ffd2a45a710
Start extGCD a = 2 b = 1 x = 140632707166152 &x = 0x7ffd2a45a710 y = 94478354388928 &y = 0x7ffd2a45a718
Start extGCD a = 1 b = 0 x = 94478354388928 &x = 0x7ffd2a45a718 y = 140632707166152 &y = 0x7ffd2a45a710
Last extGCD x = 1 &x = 0x7ffd2a45a718 y = 0 &y = 0x7ffd2a45a710
End extGCD d = 1 a = 2 b = 1 x = 0 &x = 0x7ffd2a45a710 y = 1 &y = 0x7ffd2a45a718
End extGCD d = 1 a = 5 b = 2 x = 1 &x = 0x7ffd2a45a718 y = -2 &y = 0x7ffd2a45a710
End extGCD d = 1 a = 7 b = 5 x = -2 &x = 0x7ffd2a45a710 y = 3 &y = 0x7ffd2a45a718
Function Result : x= 3 y= 3 d= 1
*/
