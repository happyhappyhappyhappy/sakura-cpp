#include<iostream>

using std::endl;
using std::cout;
using std::cin;

bool twice(int& a){
    // これでは *a をつかもうとした段階でエラーが出る
    // cout << "a=" << a << ":&a=" << &a << ":*a=" << *a << endl;
    cout << "a=" << a << ":&a=" << &a << endl;
    a = a * 2;
    // 式には演算型または対象範囲外の列挙型を使用する必要があります
    // &a = &a *2;
    cout << "a=" << a << ":&a=" << &a << endl;
    return true;
}

int main(int argc, const char** argv) {
    int x;
    int* y;
    x = 721;
    *y = 721;
    //  オペランド '*' はポインターである必要がありますが、型 "int" が指定されています
    // cout << "x=" << x << ":&x=" << &x << ":*x" << *x;
    cout << "x=" << x << ":&x=" << &x << endl;
    cout << "y=" << y << ":&y=" << &y << ":*y=" << *y << endl; 
    twice(x);
    // 型 "int &" の参照 (const で修飾されていない) は型 "int *" の値では初期化できません
    // twice(y);
    cout << "x=" << x << ":&x=" << &x << endl;
    return 0;
}
/** output
x=721:&x=0x7ffe440a838c
y=0x7ffe440a8490:&y=0x7ffe440a8390:*y=721
a=721:&a=0x7ffe440a838c
a=1442:&a=0x7ffe440a838c
x=1442:&x=0x7ffe440a838c
**/