#include<iostream>
using namespace std;
using ll = long long;

ll modinv(ll a,ll m){
    ll b,u,v;
    b = m;
    u = 1;
    v = 0;
    while(b){
        ll t = a / b;
        a = a - b * t;
        swap(a,b);
        cout << "Now a =" <<  a << endl;
        cout << "Now b =" << b << endl;
        u = u - t * v;
        swap(u,v);
        cout << "Now u =" <<  u << endl;
        cout << "Now v =" << v << endl;
    }
    u = u % m;
    if(u < 0){
        u = u + m;
    }
    cout << "ReturnNG " << u << endl;
    return u;
}

int main(int argc, const char** argv) {
    const int MOD = 1000000007;
    ll a;
    ll b;
    a = 12345678900000;
    b = 100000;
    ll b1 = 100000;
    ll gyakugen;
    gyakugen = modinv(b,MOD);
    // cout << "gyakugen = " << gyakugen << endl;
    a = a % MOD;
    // cout << a * modinv(b,MOD) % MOD << endl;
    cout << (a * gyakugen) % MOD << endl;
    return 0;
}
