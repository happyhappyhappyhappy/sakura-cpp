#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<string>
// 文字列と1ケースだけ検証
using namespace std;
#define dataStr "abcdefghijlmnopqrstuvwxyz"
// #define dataStr "abcdefg"
bool index_change_one_to_zero(int& x,int& y){
    bool result=false;
    cout << "x : " << x << "\n";
    cout << "y : " << y << "\n";
    if(x < y){
        result=true;
        y = y - 1;
        x = x - 1;
        return result;
    }
    return result;    
}

int main(int argc, char const *argv[])
{
    string inputStr=dataStr;
    string resultStr;
    cout << "inputStr-->" << inputStr << "\n";
    int from_pos,end_pos;
    cout << "Please from position and to position (1-index)\n";
    cin >> from_pos >> end_pos;
    
    if(!index_change_one_to_zero(from_pos,end_pos)){
        cout << "Please select x < y \n" ;
        cout << "your data : From = " << from_pos << " : To " << end_pos << "\n";
        return 2;
    }
    resultStr = inputStr.substr(from_pos,end_pos-from_pos+1);  
    cout << "---Result---\n" ;
    cout << "Selected String -> " << resultStr << "\n"; 
    /* code */
    return 0;
}