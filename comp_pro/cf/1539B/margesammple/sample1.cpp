#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<string>
using namespace std;

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tmp,problem_line;
    string themeString,ansString;
    cin >> tmp >> problem_line;
    cin >> themeString;
    cout << themeString;
    for (int i = 0; i < problem_line; i++)
    {
        int from_pos,to_pos;
        cin >> from_pos >> to_pos;
        index_change_one_to_zero(from_pos,to_pos);
        ansString = themeString.substr(from_pos,to_pos-from_pos+1);
        cout << ansString << "\n";
    }
    
    return 0;
}
