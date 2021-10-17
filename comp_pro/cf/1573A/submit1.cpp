#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}

ll solver(string inputNum){
    ll result = 0;
    ll numSize = inputNum.size();
    vector<int> eachNums(numSize);
    for(int j=0;j < numSize;j++){
        eachNums[j]=int(inputNum[j]) - int('0');
        cout << eachNums[j] << "\n";
    }
    return result;
}

int main(void){

    static int probNum=1;
    // 問題の場合は↑をコメント、下のコメントを外すこと
    // int probNum;
    // cin >> probNum;
    for(int j=0;j<probNum;j=j+1){
        int digits;
        cin >> digits;
        string digitsNum;
        cin >> digitsNum;
        cout << solver(digitsNum) << "\n";
    }
    return 0;
}