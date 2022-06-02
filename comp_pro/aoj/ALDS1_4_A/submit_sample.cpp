#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

bool searchA(int A[],int n,int key){
    bool result = false;
    /** 
    for(int j=0;j<n;j++){
        cout << A[j] << " ";
    }
    cout << "\n" << flush;
    **/
   int j=0;
    while(A[j] != key){
        j = j + 1;
    }
    if(j!=n){
        result = true;
    }
    return result;
}

int main(void){
    int i,n,A[10000+1],q,k;
    int sum=0;
    cin >> n;
    for(int j=0;j<n;j=j+1){
        cin >> A[j] ;
    }
    cin >> q;
    for(int j=0;j<q;j=j+1){
        cin >> k;
        bool check=false;
        check = searchA(A,n,k);
        if(check){
            sum = sum + 1;
        }
    }
    cout << sum << "\n" << flush;
    return 0;
}