#include<iostream>
#include<functional>
// 2021/12/14
// logical_andの検証
using namespace std;
int main(void){
    bool result;
    int a,b;
    a = 10;
    b = 20;
    result = logical_and<bool>()(a == 10,b == 19);
    cout << result << "\n" << flush;
    return 0;
}