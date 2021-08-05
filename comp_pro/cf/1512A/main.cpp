#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

int check_process(vector<int>& org_call,vector<int>& check_call){
    int result = -1;
    sort(check_call.begin(),check_call.end(),
    [](int a,int b)
    {
        return a < b;
    });
    for(int j=0;j<org_call.size();j=j+1){
        if(check_call.at(1) != org_call.at(j)){
            result = j+1;
        }
    }
    return result;
}

int copy_callList(vector<int>& from_data,vector<int>& to_data){
    int result = -1;
    copy(from_data.begin(),from_data.end(),back_inserter(to_data));
    return result;
}

int check_spy(int memberNo,vector<int>& member_call){
    int result=-1;
    vector<int> sorted_call;
    copy_callList(member_call,sorted_call);
    result = check_process(member_call,sorted_call);
    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase;
    cin >> testcase;
    for (auto i = 0; i < testcase; i=i+1)
    {
        int member;
        cin >> member;
        vector<int> member_call (member);
        for(int& e:member_call){
            cin >> e;
        }
        cout << check_spy(member,member_call) << "\n";
    }
    

    return 0;
}
