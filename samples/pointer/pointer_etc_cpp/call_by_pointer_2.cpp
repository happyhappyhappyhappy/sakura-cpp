#include<iostream>
// 中身を見たい 
// 
using std::cout;
using std::endl;

bool twice(int *a){
    bool ret = true;
    cout << "*a=" << *a << ":" << a << endl;
    *a = *a *2;
    cout << "*a=" << *a << ":" << a << endl;
    return ret;
}

int main(int argc, const char** argv) {
    int x;
    x = 20;
    cout << "x=" << x << ":" << &x << "(&x)" << endl;
    twice(&x);
    cout << "x=" << x << ":" << &x << "(&x)" << endl;
    return 0;
}