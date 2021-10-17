#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}

int solver(string inputNum){
    int result = 0;
    int numSize = inputNum.size();
    vector<int> eachNums(numSize);
    for(int j=numSize-1;j >= 0 ; j=j-1){
        eachNums[j]=int(inputNum[j]) - int('0');
        cout << "Position : " << j << " Num:  " << eachNums[j] << "\n";
        if(eachNums[j] != 0){
            result = result + eachNums[j] + min(j,numSize-j-1);
            cout << "Now Result:  " << result << "\n";
        }
        // cout << eachNums[j] << "\n";
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