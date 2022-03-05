#include<bits/stdc++.h>
#include<math.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    double pi8,pi12;
    double sqrt2 = sqrt(2.0);
    double sqrt3 = sqrt(3.0);
    pi8 = 4*sqrt(2-sqrt2);
    pi12 = 6*sqrt(2-sqrt3);
    cout << "Pi for 8 : " << pi8 << "\n" << flush;
    cout << "Pi for 12 : " << pi12 << "\n" << flush;
    return 0;
}
