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
    double allpattern = 6*6*6;
    for(double d=1;d<=1000;d++){
        double counter=0;
        for(double f=1;f<=6;f++){
            for(double s=1;s<=6;s++){
                for(double fo=1;fo<=6;fo++){
                    double manu=f*s*fo;
                    if((int)manu%(int)d==0){
                        counter=counter+1.0;
                    }
                }
            }
        }

        double answer=0.0;
        answer = counter / allpattern;
        cout << "Case :" << (int)d << 
        " count : " << (int)counter << " ⇒ " <<  
        answer << "\n" << flush; 
    }
    return 0;
}
