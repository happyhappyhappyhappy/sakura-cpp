#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
#define debug(...) fprintf(stderr,__VA_ARGS__)
template<class XXX> void chmin(XXX &x,XXX y){
    if(x > y){
        x = y;
    }
}

int main(void){
    int all_menber,relatedpat;
    cin >> all_menber >> relatedpat;
    vector<vector<int>> R(all_menber,vector<int>(all_menber,0));
    for(int j=0;j<relatedpat;j=j+1){
        int you , ai;
        cin >> you >> ai;
        R[you][ai]=1;
        R[ai][you]=1;
    }
    for(int j=0;j<all_menber;j=j+1){
        for(int k=0;k<all_menber;k=k+1){
            cout << R[j][k] << " ";
        }
        cout << "\n" << flush;
    }
    for(int j=0;j<all_menber;j=j+1){
        vector<int> party; // ここから値が伝染するのでひとまず初期値は無し。
        party.push_back(j); // ひとまずその人は加えておく
        for(int k=0;k<all_menber;k=k+1)
        {
            int party_len=party.size();
        }
    }   
    return 0;
}