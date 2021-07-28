#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

bool setAccumrate(vector<long> &acc,string problem_str){
    bool result = false;
    int a_code = int('a');
    acc[0] = 0;
    for(long i=0;i<problem_str.size();i++)
    {
        char now_char = problem_str.at(i);
        int now_char_code = int(now_char);
        acc[i+1] = acc[i] + (now_char_code-a_code+1);
    }

    result = true;
    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int string_size,problem_no;
    cin >> string_size >> problem_no;
    string problem_str;
    cin >> problem_str;
    vector<long> acc(100007);
    setAccumrate(acc,problem_str);
    for (long i = 0; i < string_size+1; i++)
    {
        cout << acc[i] << " ";
    }
    cout << "\n";
    for(long i = 0; i < problem_no;i++){
        // ignore
        long tmp1;
    }
    return 0;
}
