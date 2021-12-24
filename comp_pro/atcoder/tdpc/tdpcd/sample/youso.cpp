#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

int main(void){

    int x2,x3,x5;
    x2 = int(ceil(100.0 * (log(6)/log(2))));
    x3 = int(ceil(100.0 * (log(6)/log(3))));
    x5 = int(ceil(100.0 * (log(6)/log(5))));
    cout << "6^100 = 2^ " << x2 << "\n" << flush;
    cout << "6^100 = 2^ " << x3 << "\n" << flush;
    cout << "6^100 = 2^ " << x5 << "\n" << flush;

    
    return 0;
}

// 6^100 = 2^ 259
// 6^100 = 2^ 164
// 6^100 = 2^ 112