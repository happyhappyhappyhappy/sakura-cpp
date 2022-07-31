#include<bits/stdc++.h>
#include<map>
using namespace std;
using ll=long long;
#define COUT(x) cout<<#x<< " = " <<(x)<< " (L" <<__LINE__<< ")" <<"\n" << flush

// 一つの文字列を入れてみるテストプログラム
int main(void){

    string input_str;
    cin >> input_str;
    cout << input_str << "\n" << flush;
    int length = input_str.length();
    std::set<char> str_m;
    for(int j=0;j<length;j++){
        str_m.insert(input_str.at(j));
    }
    int m_length=0;
    m_length = str_m.size();
    cout << "/"" << input_str << ""/ 's charactor : " 
    << m_length << "\n" << flush; 
    return 0;
}