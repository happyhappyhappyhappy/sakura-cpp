#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

bool copy_vector(vector<int> callNum)
{
    bool result = false;
    vector<int> toCopyVector;
    copy(callNum.begin(),callNum.end(),back_inserter(toCopyVector));
    cout << "----Copyed Vector----\n";
    for (int&  e:toCopyVector)
    {
        cout << e << " ";
    }
    cout << "\n";
    
    result = true;
    return result;
}
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
    member_call_input(member_cnt,member_call);
    if(copy_vector(member_call) == true){
        cout << "OK\n";
        return 0;
    }
    else{
        cout << "NG\n";
        return 1;
    }
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

    // return 0;
}
