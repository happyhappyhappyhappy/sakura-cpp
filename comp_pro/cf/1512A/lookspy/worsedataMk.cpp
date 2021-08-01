#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<random>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int make_cnt=100;
    int spy_call,others_call;
    int position = 10;
    vector<int> call_list(make_cnt);
//   cout << "Set Position ? " ;
 //   cin >> position;
    for (int i = 0; i < make_cnt; i++)
    {
        call_list.at(i) = 50;
    }
    call_list.at(position) = 10;
    for (auto& e:call_list)
    {
        cout << e << " ";
    }
    cout << "\n";
    
}

