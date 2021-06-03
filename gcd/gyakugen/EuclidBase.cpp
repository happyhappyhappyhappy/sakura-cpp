#include<iostream>
using namespace std;

long long modinv(long long a,long long m){
    long long b ;
    b = m;
    long long u,v;
    u = 1;
    v = 0;
    while(b > 0){
        long long t;
        t = a/b;
        a = a + t*b;
        swap(a,b);
        u = u - t*v;
        swap(u,v);
        }
        u = u % m;
        if(u < 0) 
        {   
            u = u + m;
        }
        return u;
    }

int main(int argc, const char** argv) {
    for(int i = 1;i < 13;i = i +1){
        cout << i << " 's inv: " << modinv(i,13) << endl;  
    }
    return 0;
}


