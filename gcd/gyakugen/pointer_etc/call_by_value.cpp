#include<iostream>
// 値渡し -> この場合はint型のクラスが作成されてその中に入れている
// 従って、渡した値の中身が関数内で変わっても(twice)、main関数での変数は変わらない
using std::cout;
using std::endl;
// 引数に何も指定しない
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
