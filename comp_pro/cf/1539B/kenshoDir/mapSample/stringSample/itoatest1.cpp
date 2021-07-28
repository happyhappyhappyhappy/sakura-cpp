#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    int charint;
    charint = 42;
    auto a = char(charint);
    cout << charint << " is " << a << "\n";
    cout << "逆→文字から数値へ" << "\n";
    char c1;
    c1 = 'g';
    auto i1 = int('g');
    cout << c1 << " to " << i1 << "\n";
    
    return 0;
}
