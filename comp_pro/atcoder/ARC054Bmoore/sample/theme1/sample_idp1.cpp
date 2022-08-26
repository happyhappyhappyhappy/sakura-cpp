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
double func(double x){
    return pow(x,2.0)-6.0*x+10.0;
}
void get_point(double left,double &gleft,double &gright,double right){
    // 3分探索用仮の黄金比
    static double GOLD=2.0;
    static double DENOMI=pow((GOLD+1.0),-1.0);
    // static double GOLD= ここに本当の黄金比を入れる
    // 1:2になる点はgleftの中身になる
    gleft = (left*GOLD+right)*DENOMI;
    // 2:1になる点はleftの中身になる
    gright = (left+right*GOLD)*DENOMI;
}


int main(void){
    initial();
    double left=0;
    double right=100;
    int roop=300;
    while(roop--){
        if((right-left)<0.00000001){
            break;
        }
        double gleft;
        double gright;
        get_point(left,gleft,gright,right);
        if(func(gleft)<func(gright)){
            right = gright;
        }
        else{
            left = gleft;
        }
        cout << "LOOP : " << roop << " LEFT: " << left << " RIGHT: " << right
        << "\n" << flush;
    }
    cout << "LAST -> " << func((left+right)*pow(2.0,-1.0)) 
    << "\n" << flush;
    return 0;
}
