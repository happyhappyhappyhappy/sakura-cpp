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
double func(double NOW_TIME){
    return NOW_TIME;
}
void golden_point(double left,double &gleft,double &gright,double right){
    
}

double solver(double NOW_TIME){
    double left=0.0;
    double right=NOW_TIME;
    int counter=300;
    while(counter--){
        if(abs(right-left)>0.000000001){
            break;
        }
        double gleft;
        double gright;
        golden_point(left,gleft,gright,right);
        if(func(gleft)<func(gright)){
            // rightを左に寄せる
            right=gright;
        }
        {
            // leftを左に寄せる
            left=gleft;
        }
        cout << "TERM " << count << ":left " << left 
        << " " << ":right " << right << "\n" << flush;
    }
    cout << "LAST LEFT: " << left << " RIGHT: " << right << "\n" << flush;  
    return func((right+left)*pow(2.0,-1.0));
}
int main(void){
    initial();
    double now_time;
    cin >> now_time;
    cout << solver(now_time) << "\n" << flush;
    return 0;
}
