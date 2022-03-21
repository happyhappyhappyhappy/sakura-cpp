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

    bool result=true;/**
    for(auto x:v){
        cout << x << " " ;
    }
    cout << "\n" << flush;**/
    int v_size=v.size();
    // vector<int> answer(v_size);
    for(int j = 0;j<v_size;j++){
        if(v.at(j) != j+1){
//            cout << "要素 :" << v.at(j) << " が " << j+1
//            << "ではありません";
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
    for(int j=0;j<v_size;j++)
    {
        if(v[j] != v_copy[j])
        {
            k=j;
            k_value=v_copy[j];
            break;
        }
    }
    // k_vakueとなる位置を探す
    int k_value_pos=-1;
    for(int j=0;v_size;j++)
    {
        if(v[j] == k_value)
        {
            k_value_pos=j;
            break;
        }
    } 
    reverse(v.begin()+k,v.begin()+k_value_pos+1);
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    for(int x=0;x<testcase;x++){
        int length;
        cin >> length;
        vector<int> v(length);
        for(int y=0;y<length;y++){
            cin >> v[y];
        }
        if(okperm(v)==false){
            solve(v);
        }
        for(int y=0;y<length;y++){
            cout << v[y] << " ";
        }
        cout << "\n" << flush;
    }
    return 0;
}