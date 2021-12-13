#include<iostream>
using namespace std;
int main(void){
    [](int n){cout << "Lambda\t" << n << "\n" << flush;}
    (0);

    auto sample = [](int n){
        cout << "sample\t" << n << "\n" << flush; 
    };
    sample(10);
    sample(123);
    return 0;
}