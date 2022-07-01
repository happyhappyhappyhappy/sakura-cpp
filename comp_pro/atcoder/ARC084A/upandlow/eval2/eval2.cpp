#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
int solver_h(vector<int> &H,int key){
    int left=-1;
    int right=H.size();
    while(abs(right-left)>1){
        int mid=(right+left)/2;
        if(key < H[mid]){
            right = mid;
        }
        else{
            left=mid;
        }
    }
    return right;
}
int solver_u(vector<int> &UPP,int key){
    int index = 0;
    index = upper_bound(UPP.begin(),UPP.end(),key)-UPP.begin();
    return index;
}
int main(void){
    int n;
    int key;
    int ans;
    cin >> n;
    vector<int> U(n);
    for(int j=0;j<n;j++){
        cin >> U[j];
    }
    cin >> key;
    cin >> ans;
    int hand_index,default_index;
    hand_index=solver_h(U,key);
    default_index=solver_u(U,key);
    cout << "----------------\n配列 ";
    for(int j=0;j<n;j++){
        cout << U[j] << " ";
    }
    cout << "\n";
    cout << "std::upper_bound: " << default_index << "\n";
    cout << "めぐる式         : " << hand_index << "\n";
    if(default_index==hand_index){
        cout << "回答値は一致しています\n";
    }
    else{
        cout << "回答値が一致していません\n";
    }
    cout << "想定している値は " << ans << " です\n";
    return 0;
}
