#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

bool member_call_input(int member_cnt,vector<int>& callNum){
    bool result=false;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    callNum.resize(member_cnt);
    for(int& call_data:callNum){
        cin >> call_data;
    }
    result = true;
    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int member_cnt;
    cin >> member_cnt;
    vector<int> member_call;
    /**   if(member_call_input(member_cnt,member_call)){
        cout << "This is input call. \n";
        for(int& e:member_call){
            cout << e << " ";
        }
        cout << "\n";
    }
    else{
        cout << "ERROR!! \n";
    }**/

    return 0;
}
