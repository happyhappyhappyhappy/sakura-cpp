// for_eachの関数設定確認
// https://cpprefjp.github.io/reference/algorithm/for_each.html
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void disp(int x){
    cout << x << " ";
}
int main(void){
    vector<int> v={3,1,4,1,5};
    for_each(v.begin(),v.end(),disp);
    cout << "\n" << flush;
}