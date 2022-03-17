#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool okperm(vector<int>& v){

    bool result=true;
    for(auto x:v){
        cout << x << " " ;
    }
    cout << "\n" << flush;
    int v_size=v.size();
    // vector<int> answer(v_size);
    for(int j = 0;j<v_size;j++){
        if(v.at(j) != j+1){
            cout << "要素 :" << v.at(j) << " が " << j+1
            << "ではありません";
            result = false;
            break;
        }
    }
    return result;
}
void solve(vector<int>& v){
    int v_size=v.size();
    vector<int> v_copy(v_size);
    for(int j=0;j<v_size;j=j+1){
        v_copy[j] = j+1;
    }
    // まずは1,2,3...として途中外れる位置kを探す
    int k = -1;
    int k_value = -1;
    for(int j=0;j<v_size;j++){
        if(v[j] != v_copy[j]){
            k=j;
            k_value=v_copy[j];
            break;
        }
    }
    //  
}
int main(void){
    initial();
    int testcase=1;
    cin >> testcase;
    for(int j=0;j<testcase;j=j+1){
        int element;
        cin >> element;
        vector<int> v(element);
        // TODO: 値を入れる処理を行ってください
        for(int j=0;j<element;j=j+1){
            cin >> v[j];
        }
        /**
         for(int j=0;j<element;j=j+1){
            cout << v[j] << " ";
        }
        cout << "\n" << flush;
        **/
        bool needmod=false;
        needmod = okperm(v);
        if(needmod){
            solve(v);
            }
        for(int j=0;j<element;j=j+1){
            cout << x[j] << " ";
        }
        cout << "\n" << flush;
        v.clear();
        }
    }
    return 0;
}
