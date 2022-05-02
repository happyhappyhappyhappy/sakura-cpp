#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

string solver(vector<ll> v){
    // TODO: まずは1個しか値が無い場合を考える 
    sort(v.begin(),v.end());
    // TODO: それ以外の数はひたすら比較する
    /**
    for(auto& e:v){
        cout << e << " ";
    }
    cout << "\n" << flush;
    **/
    return "NO";
}
int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    while(--testcase >= 0){
        int valueno;
        cin >> valueno;
        vector<ll> asort(valueno);
        for(auto& e:asort){
            cin >> e;
        }
        /**
        cout << "入力後" << "\n" << flush;
        for(auto& e:asort){
            cout << e << " ";
        }
        cout << "\n" << flush;
        **/
       cout << solver(asort) << "\n" << flush;
    }
    return 0;
}
