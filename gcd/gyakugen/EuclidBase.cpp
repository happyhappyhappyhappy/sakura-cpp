#include<iostream>
using namespace std;

long long modinv(long long a,long long m){
    long long b ;
    b = m;
    long long u,v;
    u = 1;
    v = 0;
    while(b){
        long long t;
        t = a/b;
        a = a - t*b;
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
    cout << "7 's inv: " << modinv(7,5) << " mod 5" << endl;
    return 0;
}
/** Result 
under mod 13
1 's inv: 1
2 's inv: 7
3 's inv: 9
4 's inv: 10
5 's inv: 8
6 's inv: 11
7 's inv: 2
8 's inv: 5
9 's inv: 3
10 's inv: 4
11 's inv: 6
12 's inv: 12
7 's inv: 3 mod 5
*/  

