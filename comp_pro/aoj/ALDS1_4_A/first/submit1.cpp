#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

bool solver(vector<int> &S,int n,int key){
    bool result = false;
    S[n] = key;
    int j=0;
    while(S[j] != key){
        j=j+1;
    }
    if(j!=n){
        result = true;
    }
    return result;
}
void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int n;
    cin >> n;
    vector<int> S(100001);
    for(int j=0;j<n;j++){
        cin >> S[j];
    }
    int q;
    cin >> q;
    int result=0;
    vector<int> T(q);
    for(auto &x:T){
        cin >> x;
    }
    for(int j=0;j<q;j++){
        if(solver(S,n,T[j])){
            result = result + 1;
        }
    }
    cout << result << "\n" << flush;
    return 0;
}
