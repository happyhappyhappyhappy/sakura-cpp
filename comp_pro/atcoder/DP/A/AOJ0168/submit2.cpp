#include<bits/stdc++.h>
using namespace std;
const int dptable = 31;
const int default_comv = 0;

int main(void){
    vector<int> dp(dptable);
    for(int j=0;j<dptable;j=j+1){
        dp[j] = default_comv;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = dp[1] + 1;
    dp[3] = dp[2] + dp[1] + 1;
    for(int j=4;j<dptable;j++){
        dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
    }
    while(true){
        int position;
        int answer;
        cin >> position;
        if(position == 0){
            break;
        }
        answer = (dp[position]+3650) / 3650;
        cout << answer << "\n";
    }
    return 0;
}