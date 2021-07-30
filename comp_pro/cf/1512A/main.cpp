#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

int check_spy(int memberNo,vector<int> member_call){
    vector<int> sorted_call(memberNo);
    for(int j=0;j<memberNo;j=j+1){
        sorted_call.at[j] = sorted_call.at[j];
    }
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
        for(int e:member_call){
            cin >> e;
        }
        cout << check_spy(member,member_call) << "\n";
 
    }
    

    return 0;
}
