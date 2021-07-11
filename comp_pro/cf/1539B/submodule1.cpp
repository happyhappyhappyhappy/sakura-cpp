#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<string>

using namespace std; 

vector<int,int> checkProcess(string inputStr){
    vector<int,int> result(int('z')-int('a')+1);
    int a_i = int('a');
    int z_i = int('z');
    for (int i = a_i-a_i ; i <= z_i - a_i; i++)
    {
        auto output_i = char(i+'a');
        cout << i << " : " << output_i << "\n";
    }
    return result;
}
    
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string inputStr;
    cin >> inputStr;
    vector<int,int> resultStr(int('z')-int('a')+1);
    resultStr = checkProcess(inputStr);
/**    for (int i = int('a')-int('a'); i <= int('z')-int('a'); i++)
    {
        cout << char(i+int('a')) << "の個数→" << resultStr[i] < "\n";
    }
**/ 
    return 0;
}
