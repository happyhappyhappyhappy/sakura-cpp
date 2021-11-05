#include<iostream>
using namespace std;
template<class T> inline chmax(T& a,T b)
    {
        if( a < b )
            {
                a = b;
                return true
            }
        return false;
    }
// TODO 写経の際は型に注目しよう
