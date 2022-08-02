#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int solver(string &input_str){
    int days = 1;
    set<char> his_memory;
    for(int j=0;j<input_str.size();j=j+1){
        char getHaveChar=input_str.at(j);
        const int HISCANCHARS = 3;
        his_memory.insert(getHaveChar);
        // cout << getHaveChar << " insert\n" << flush; 
        if(HISCANCHARS < his_memory.size()){// もう彼が覚えられなくなったら
            his_memory.clear();
            days=days+1; // 次の日もう一回入れる
        //    cout << days << " day...input " << "\n" << flush;
            his_memory.insert(getHaveChar);
        }
    }
    return days;
}

int main(void){
    initial();
    int testcase=0;
    cin >> testcase;
    while(testcase--){
        string words;
        cin >> words;
        cout << solver(words) << "\n" << flush;
    }
    return 0;
}
