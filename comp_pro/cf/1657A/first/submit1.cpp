#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool is_squar(int D){
    bool result=false;
    int check_j=1;
    while(check_j*check_j < D){
        check_j=check_j+1;
    }
    if(check_j*check_j==D){
        cout << check_j*check_j << "\n" << flush;
        result = true;
    }
    return result;
}

int solver(int x,int y){
    int result=-1;
    int sidesum = x*x + y*y;
    cout << sidesum << "\n" << flush;
    if(sidesum == 0){
        return 0;
    }
    if(is_squar(sidesum)){
        result = 1;
    }
    else{
        result = 2;
    }
    return result;
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int t=0;t<testcase;t++){
        int x;
        int y;
        cin >> x >> y;
        cout << solver(x,y) << "\n" << flush;
    }
    return 0;
}
