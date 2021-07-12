#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<map>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string inputStr;
    map<char,int> charMap;

    cin >> inputStr;
    for (int i = 0; i < inputStr.size(); i++)
    {
        if(charMap.count(inputStr.at(i))==0){
            charMap.insert(make_pair(inputStr.at(i),1));
        }
    }       
    cout << inputStr <<  "に存在する文字" << "\n";
    for(auto itr = charMap.begin();itr != charMap.end();itr++ ){
        cout << itr->first << "\n";
    }
    return 0;
}
