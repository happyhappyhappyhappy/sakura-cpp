#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int j=0;j<testcase;j=j+1){
        vector<int> base_d(4);
        for(auto e : base_d){
            cin >> e;
        }
        vector<int> price(base_d[0]);
        for(auto e : price){
            cin >> e;
        }
        int answer = solver(base_d,price);
        cout << answer << "\n" << flush;
    }
    return 0;
}
