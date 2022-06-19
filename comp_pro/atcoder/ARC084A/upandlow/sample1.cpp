#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void mybinaryChecker(vector<int> &X,int &b){
    sort(X.begin(),X.end());
    for(auto &x:X){
        cout << x << " ";
    }
    cout << "\n" << flush;
    cout << "input : " << b << "\n" << flush;
    int pos_l=lower_bound(X.begin(),X.end(),b)-X.begin();
    cout << "lower_bound case: " << pos_l << " \n" << flush;
    int pos_u=upper_bound(X.begin(),X.end(),b)-X.begin();
    cout << "upper_bound case: " << pos_u << " \n" << flush;
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