#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

int main(void){
    initial();
    // TODO コンパイルから
    double allpattern = 6*6*6;
    for(ll d=1;d<=100;d++){
        ll counter=0;
        for(ll f=1;f<=6;f++){
            for(ll s=1;s<=6;s++){
                for(ll fo=1;fo<=6;fo++){
                    ll manu=f*s*fo;
                    if(manu%d==0){
                        counter=counter+1;
                    }
                }
            }
        }

        double answer=0.0;
        answer = counter / allpattern;
        cout << "Case :" << d << 
        " count : " << counter << " ⇒ " <<  
        answer << "\n" << flush; 
    }
    return 0;
}
