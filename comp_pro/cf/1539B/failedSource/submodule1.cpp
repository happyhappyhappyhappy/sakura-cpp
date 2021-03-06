#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<string>
#include<map>
using namespace std; 

bool checkProcess(string inputStr,map<char,int> &charCounter){
    int multiple;
    multiple = 1;
    for (int i = 0; i < inputStr.size(); i++)
    {
        if(charCounter.count(inputStr.at(i))==0){
            charCounter.insert(make_pair(inputStr.at(i),multiple));
        }
        else{
            continue;
        }
        multiple = multiple + 1;
    }    
    return true;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string inputStr;
    cin >> inputStr;
    map<char,int> charCounter;
    checkProcess(inputStr,charCounter);
    cout << "-----" << inputStr << "に含まれる文字とそれに対する倍数-----" << "\n";
    for(auto itr=charCounter.begin();itr !=charCounter.end();itr++){
        cout << itr->first << " : " << itr->second << "\n";
    }
    return 0;
}
/**
 * テスト結果
 -----abacabaに含まれる文字とそれに対する倍数-----
a : 1
b : 2
c : 3
-----abbabaaに含まれる文字とそれに対する倍数-----
a : 1
b : 2
-----sonoshikumiwoに含まれる文字とそれに対する倍数-----
h : 4
i : 5
k : 6
m : 8
n : 3
o : 2
s : 1
u : 7
w : 9
 **/