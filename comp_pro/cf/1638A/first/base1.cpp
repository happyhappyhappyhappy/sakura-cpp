#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
// reverse関数の利用法を検証する

int main(void){
    int rowlength;
    cin >> rowlength;
    vector<int> a(rowlength);
    for(int j=0;j < rowlength;j++){
        int inputI;
        cin >> inputI;
        a[j] = inputI;
    }
    for(int j=0;j<rowlength;j++){
        cout << a[j] << " ";
    }
    cout << "\n" << flush;

    //reverse(a.begin(),a.end());
    
    reverse(a.begin()+3,a.begin()+7);
    cout << "reverse後:" << "\n" << flush;
    for(int j=0;j<rowlength;j++){
        cout << a[j] << " ";
    }
    cout << "\n" << flush;
    return 0;
}