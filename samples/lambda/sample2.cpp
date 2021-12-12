#include<iostream>
using namespace std;

int main(void){
    [](int n){cout << "simple lambda\t" << n << "\n" << flush; }(10);
    auto TEST = [](int x){
        cout << "TEST\t" << x << "\n" << flush;
    };
    TEST(10);
    TEST(100);
    TEST(200);
    return 0;
}