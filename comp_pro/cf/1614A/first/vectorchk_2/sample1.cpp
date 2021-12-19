#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(vector<int>& base_d){
    for(auto e:base_d){
        cout << e << " ";
    }
    cout << "\n" << flush;
    return 0;
}

int main(void){
    initial();
    vector<int> prob_d(4);
    for(auto& e:prob_d){
        cin >> e;
    }
    solver(prob_d);
    return 0;
}
