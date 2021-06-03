#include<iostream>

using std::endl;
using std::cout;
using std::cin;

bool twice(int *a){
    if(a==nullptr){ // 検出できればOK
        cout << "This is NULL" << endl;
        return true;
    }
    cout << "*a= " << a << " is Not Null" << endl;
    *a = *a *2;
    cout << "*a = " << *a << ":" << a  << endl;
    return false;  
}

int main(int argc, const char** argv) {
    int x;
    if(twice(nullptr)){
        cout << "Null Check" << endl;
        cout << "----------" << endl;
    };
    x = 10;
    cout << "x=" << x << ":" << &x << endl ;
    if(twice(&x) != true)
        {
            cout << "x=" << x << ":" << &x << endl ; 
        }
    return 0;
}