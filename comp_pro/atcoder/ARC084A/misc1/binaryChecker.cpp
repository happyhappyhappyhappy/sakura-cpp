#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

bool isOK(int &check,int &base){
    bool result=false;
    if(check>base){
        result = true;
    }
    return result;
}

void mybinaryChecker(vector<int> &X,int &b){
    int ok=X.size();
    int ng=-1;
    while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;
        if(isOK){
            ng=mid;
        }
        else{
            ok=mid;
        }
    }
    cout << "V's OK position is " << ok << endl;
}
int main(void){
    int base;
    cin >> base;
    int size;
    cin >> size;
    vector<int> V(size);
    for(int j=0;j<size;j++){
        cin >> V[j];
    }
    mybinaryChecker(V,base);
    return 0;
}