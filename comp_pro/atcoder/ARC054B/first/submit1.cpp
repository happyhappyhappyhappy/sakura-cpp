#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << setiosflags(ios::fixed);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
double func(double value,double P){
    double denomi = pow(2.0,3.0*value*pow(2.0,-1.0));
    return value+P*pow(denomi,-1.0);
}
void golden_point(double left,double &gleft,double &gright,double right){
    static double GOLD=(1.0+sqrt(5.0))*pow(2.0,-1.0); // 黄金比
    static double DENOMI=pow((GOLD+1.0),-1.0); // 分母
    gleft=(left*GOLD+right)*DENOMI;
    gright=(left+GOLD*right)*DENOMI;
}

double solver(double P){
    double left=0.0;
    double right=P;
    int counter=300;
    while(counter--){
        if(abs(right-left)<0.000000001){
            break;
        }
        double gleft;
        double gright;
        golden_point(left,gleft,gright,right);
        if(func(gleft,P)<func(gright,P)){
            // rightを左に寄せる
            right=gright;
        }
        {
            // leftを左に寄せる
            left=gleft;
        }
        cout << "TERM " << counter << ":left " << left 
        << " " << ":right " << right << "\n" << flush;
    }
    cout << "LAST LEFT: " << left << " RIGHT: " << right << "\n" << flush;  
    return func((right+left)*pow(2.0,-1.0),P);
}
int main(void){
    initial();
    double P;
    cin >> P;
    cout << solver(P) << "\n" << flush;
    return 0;
}
