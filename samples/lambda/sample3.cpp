#include<iostream>
using namespace std;

int main(void){
    cout << []() -> int{return 3.14f;}() << "\n" << flush;
    return 0;
}