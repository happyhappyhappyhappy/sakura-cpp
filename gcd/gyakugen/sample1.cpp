#include<iostream>
using namespace std;
// using ll=long long;

long long modpow(long long a,long long n,long long mod){
    long long res = 1;
    while(n > 0)
        {
        if(n & 1)
            {
            res = (res * a) % mod;
            }
        a = (a * a) % mod; 
        n = n >> 1;
    }
    return res;
}

long long modinv(long long a,long long mod){
    return modpow(a,mod-2,mod);
}

int main(int argc, const char** argv) {
    const long long mod=13;
    for(int i = 1; i< mod+2; ++i){
        cout << i << "'s inv: " << modinv(i,mod) << " mod: " << mod << endl;
    }
    return 0;
}
