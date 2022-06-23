#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool isCheckOK(int value,int key){
    if(key <= value){
        return true;
    }
    return false;
}

int mylob(int key,vector<int> &A){
    int ng=-1;
    int ok=A.size();
    while(abs(ok-ng)>1){
        int mid;
        mid = (ok+ng)/2;
        if(isCheckOK(A[mid],key)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    return ok;
}

int main(void){
    initial();
    int key;
    int indexes;
    cin >> key;
    cin >> indexes;
    vector<int> A(indexes);
    for(int j=0;j<indexes;j++){
        int adata;
        cin >> adata;
        A[j]=adata;
    }
    int pos;
    pos=mylob(key,A);
    cout << "Result\n";
    cout << "index_pos:\t" << pos << "\n";    
    return 0;
}
