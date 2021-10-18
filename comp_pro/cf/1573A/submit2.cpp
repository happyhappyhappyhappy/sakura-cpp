#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
// using ll=long long;

void initial(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    cout << fixed << setprecision(10);    
}

int solver(int digits,string inputStr){
    int result=0;
    for(int j=1;j<=digits;j=j+1){
        char getA;
        getA = inputStr.at(j-1);
        // 投入された文字列のそれぞれの数値を全部足し合わせる
        result = result + (int(getA)-int('0')); 
        // 数値が0ではない、かつ最後の桁以外ならば交換処理が必要なので1加える
        if(int(getA) > int('0') && j!=digits){ 
            result=result+1;
        }
    }
    return result;
}

int main(void){
    int problemNo;
    cin >> problemNo;
    for(int j=0;j<problemNo;j=j+1){
        int digits;
        string inputString;
        cin >> digits;
        cin >> inputString;
        cout << solver(digits,inputString) << "\n";
    }
    return 0;
}
