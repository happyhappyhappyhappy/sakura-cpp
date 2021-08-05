#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

int loopup_spy(vector<int>& callNum,vector<int>& copy_callNum){
    int result= -1;
    sort(copy_callNum.begin(),copy_callNum.end(),[](int a,int b)
    { return b < a ;}
    );
    /**
    cout << "---- Sorted Vector ----" << "\n";
    for (auto&e :copy_callNum)
    {
        cout << e << " ";
    }
    cout << "\n"; **/
    // int checkNum = copy_callNum.at(1);
    for(int j=0;j<callNum.size();j=j+1){
        if(callNum.at(j) != copy_callNum.at(1))
        {
            result = j+1;
        }
    }
    return result;
}

vector<int> copy_vector(vector<int> callNum)
{
    vector<int> toCopyVector;
    copy(callNum.begin(),callNum.end(),back_inserter(toCopyVector));
    /** cout << "----Copyed Vector----\n";
    for (int&  e:toCopyVector)
    {
        cout << e << " ";
    }
    cout << "\n"; **/
    
    return toCopyVector;
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
    vector<int> copy_member_call;
    member_call_input(member_cnt,member_call);
    copy_member_call = copy_vector(member_call);
    cout << loopup_spy(member_call,copy_member_call) << "\n";    
}
