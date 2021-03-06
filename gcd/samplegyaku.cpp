#include <iostream>
using namespace std;

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        cout << "Now a =" <<  a << endl;
        cout << "Now b =" << b << endl;
        u -= t * v; swap(u, v);
        cout << "Now u =" <<  u << endl;
        cout << "Now v =" << v << endl;
    }
    u %= m;
    if (u < 0) u += m;
    cout << "ReturnOK " << u << endl; 
    return u;
}

// a ÷ b mod. MOD を計算してみる
int main() {
    const int MOD = 1000000007;

    long long a = 12345678900000;
    long long b = 100000;

    // a を 10000000007 で割ってから b の逆元をかけて計算
    a %= MOD;
    cout << a * modinv(b, MOD) % MOD << endl;
}