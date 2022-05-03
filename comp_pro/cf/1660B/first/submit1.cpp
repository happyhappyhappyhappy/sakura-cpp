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
    if(v.size()==1){
        if(v[0] == 1){
            return "YES";
        }
        else{
            return "NO";
        }
    }
    else
    {
        sort(v.begin(),v.end());
        int allType = v.size();
        if(v[allType-2]+1<v[allType-1]){
            return "NO";
        }
        else{
            return "YES";
        }
    }
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
