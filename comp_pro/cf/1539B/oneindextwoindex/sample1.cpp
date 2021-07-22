/**
 1-indexから0-indexへの変更を値渡しで行います 
 **/
#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

bool change_index(int &x,int &y){
    bool result=true;
    x = x - 1;
    y = y - 1;
    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int counter;
    cin >> counter;
    for (int i = 0; i < counter; i=i+1)
    {
        int a;
        int b;
        cin >> a >> b;
        if(change_index(a,b)){
            cout << a << " " << b << " \n";
        }
    }
    return 0;
}
