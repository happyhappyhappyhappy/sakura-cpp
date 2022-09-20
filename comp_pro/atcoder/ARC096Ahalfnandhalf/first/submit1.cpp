#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MAXINT 

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(int A,int B,int AB,int X,int Y){
    int result = 1<<28;
    int surplusX=0;
    int surplusY=0;
    for(int j=0;j<=2*pow(10,5);j=j+2){
        int eachPizza= j / 2;
        if(eachPizza<X){
            surplusX=X-eachPizza;
        }
        else{
            surplusX=0;
        }
    }
    return result;
}

int main(void){
    initial();
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    cout << solver(A,B,C,X,Y) << "\n" << flush;
    return 0;
}

