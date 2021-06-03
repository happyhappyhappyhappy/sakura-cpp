#include<iostream>
// ポインタで渡す
using std::cout;
using std::endl;
//         ______この辺に注意
bool twice(int *a){
    bool ret = true;
    cout << "*a=" << *a << endl;
    *a = *a * 2;
    cout << "*a=" << *a << endl;
    return ret; 
}

int main(int argc, const char** argv) {
    int x;
    x = 20;
    cout << "x=" << x << endl;
    twice(&x);
    cout << "x=" << x << endl;
    return 0;
}