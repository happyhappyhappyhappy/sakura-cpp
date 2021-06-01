#include<iostream>
using std::cout;
using std::endl;
bool twice(int a){
    bool retcode=true;
    cout << a << endl;
    a = a * 2;
    cout << a << endl;
    return retcode;
}
int main(int argc, char const *argv[])
{
    int b;
    b = 10;
    cout << "Now b=" << b << endl;
    twice(b);
    cout << "After b=" << b << endl;
    return 0;
}
