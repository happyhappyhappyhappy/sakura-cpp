#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<vector>
using namespace std;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int member;
    cin >> member;
    vector<int> number(member);
    for (auto& e:number)
    {
        cin >> e;
    }
    // set number
    for (auto& e:number)
    {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}
