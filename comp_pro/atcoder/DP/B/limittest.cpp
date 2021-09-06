#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int turn_num=63;

int main(void){
    ll left_turn,right_turn;
    left_turn = 1LL << turn_num;
    right_turn = 1LL >> turn_num;
    cout << "左に角が立つとき\t" << left_turn << "\n";
    cout << "右に角が立つとき\t" << right_turn << "\n";
    return 0;
}