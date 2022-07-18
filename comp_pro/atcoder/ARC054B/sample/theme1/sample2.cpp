#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
long double f(long double x){
    return pow(x,2.0)-6.0*x+10.0;
}
// 黄金比
void compute_cd(double &a,double &b,double &c,double &d){
    double gold;
    GOLD = (sqrt(5.0)-1.0)/2.0;
    // TODO: どうやら全部使うみたいだ
}
int main(void){
    cout << setprecision(10) << setiosflags(ios::fixed);
    long double left,right;
    left=-100.0;
    right=100.0;
    for(int j=0;j<150;j++)// これは繰り返し回数
    {
        long double t1;
        long double t2;
        t1=(2.0*left+right)/3;
        t2=(left+right*2.0)/3;
        if(f(t1)>f(t2)){
            left = t1;
        }
        else{
            right = t2;
        }
        cout << j << " term: " << "left : " << left << " right : " << right
        << "\n" << flush;
        if(right-left<=0.000000001){
            break;
        }
    }
    
    cout << f(left) << "\n" << flush;

    
    return 0;
}