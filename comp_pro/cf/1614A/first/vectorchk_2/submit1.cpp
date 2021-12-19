#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(vector<int>& base_data,vector<int>& prices){
    int result = 0;
    for(auto& e:prices){
        cout << e << " ";
    }
    cout << "\n" << flush;
    sort(prices.begin(),prices.end());
    cout << "sort実行後\n" << flush; 
    for(auto& e:prices){
        cout << e << " ";
    }
    cout << "\n" << flush;
    return result;
}
int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int j=0;j<testcase;j=j+1){
        vector<int> base_d(4);
        for(int& e : base_d){
            cin >> e;
        }
        vector<int> price(base_d[0]);
        COUT(base_d[0]);
        for(auto& e : price){
            cin >> e;
        }
        int answer = solver(base_d,price);
        cout << answer << "\n" << flush;
    }
    return 0;
}
