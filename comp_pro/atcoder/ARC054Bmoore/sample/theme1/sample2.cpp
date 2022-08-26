#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

long double f(long double x){
    return pow(x,2.0)-6.0*x+10.0;
}

double goldsearch(double left,double right,int count){
    double x1,x2;
    double f1,f2;
    double GOLD=(1.0+sqrt(5.0))/2.0;
    double result=0;
    x1 = (right-left)/((GOLD+1)+left);
    x2 = (right-left)/(GOLD+left);
    f1=f(x1);
    f2=f(x2);
    for(int j=0;j<count;j++){
       if(f1<f2){
        right=x2;
        x2=x1;
        x1=(right-left)/((GOLD+1)+left);
        f1=f(x1);
       } 
       else{
        left=x1;
        x1=x2;
        x2=(right-left)/(GOLD+left);
        f2=f(x2);
       }
       cout << j << " : " << "left =" << left
       << " right = " << right << "\n" << flush;
    }
    result = (right+left) / 2.0;
    double last_y=f(result);
    cout << "result = " << result << 
    " last " << last_y << "\n" << flush;
    return (right+left)/2.0;
}


int main(void){
    cout << setprecision(10) << setiosflags(ios::fixed);
    cout << goldsearch(-100.0,100.0,300) << "\n" << flush;
    
    return 0;
}