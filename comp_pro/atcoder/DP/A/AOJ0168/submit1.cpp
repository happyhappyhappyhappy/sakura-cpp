#include<bits/stdc++.h>
using namespace std;
const long long dptable = 35;
const long long default_comv = 0;

long long solver(vector<long long>& dp,long long position){
    long long answer = 0;
    answer = (dp[position]+3650)/3650;
    return answer;
}
bool dp_init(vector<long long>& dp){
    bool result=true;
    for(long long j=0;j<dptable;j++){
        dp[j]=default_comv;
    }
    return result;
}
bool dp_process(vector<long long>& dp){
    bool result=true;
    dp[0] = 0;
    dp[1] = dp[0] + 1;
    dp[2] = dp[1] + 1;
    dp[3] = dp[2] + dp[1] + 1;
    for(long long  j=4;j<=dptable;j=j+1){
        dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
    //    cout << j << "\t" << dp[j] << "\n";
    }
    return result;
}

int main(void)
{
    long long  input_data;
    vector<long long> dp(dptable);
    dp_init(dp);
    dp_process(dp);
    /**
    for(long long  j=1;j<=10;j++){
        long long  answer ;
        answer = solver(dp,j);
        cout << answer << "\n";
    }**/
    while(true){
        long long  answer=0;
        cin >> input_data;
        if(input_data == 0){
            // 処理終了
            break;
        }
        answer = solver(dp,input_data);
        cout << answer << "\n";
    }
    return 0;
}
