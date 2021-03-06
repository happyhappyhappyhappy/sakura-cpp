#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush
// codeforce 1661A from 2022/04/22 ->

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll my_calc(ll first,ll second){
    ll result=first-second;
    if(0 >= result ){
        return result*(-1);
    }
    return result;
    }

ll solver(vector<ll>& a,vector<ll>& b){
    ll result=0;
    for(int j=0;j<a.size()-1;j++){
        ll first=0;
        ll second=0;
        first = my_calc(a[j],a[j+1]) + my_calc(b[j],b[j+1]);
        second = my_calc(a[j],b[j+1]) + my_calc(b[j],a[j+1]);
        if(second < first){
            swap(a[j+1],b[j+1]);
        }
    }
    for(int j=0;j<a.size()-1;j++){
        result = result + my_calc(a[j],a[j+1])+my_calc(b[j],b[j+1]);
    }
    return result;
}

int main(void){
    initial();
    int testcase=1;
    cin >> testcase;
    for(int j=0;j<testcase;j++){
        int arraylength=0;
        cin >> arraylength;
        vector<ll> v_a(arraylength);
        vector<ll> v_b(arraylength);
       for(auto& e:v_a){
            cin >> e;
        };
        for(auto& e:v_b){ // NG CONST
            cin >> e;
        };
        cout << solver(v_a,v_b) << "\n" << flush;
    }
    return 0;
}
