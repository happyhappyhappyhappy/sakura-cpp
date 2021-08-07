#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

bool resolve(string &getString){
    bool result = false;
    size_t length = getString.size();
    size_t first_find = getString.find('a');
    cout << "FirstFind : " << first_find << "\n";
    size_t L,R;
    L=first_find;
    R=first_find;
    if(first_find == string::npos){
        return result;
    }
    for (size_t i = 1; i < length; i++)
    {
        size_t find_code = getString.find(char(int('a')+i));

        if(find_code == string::npos || 
        (find_code != L-1 && find_code !=R+1) ){
            return result;
        }
        else{
           min(L,find_code);
           max(R,find_code);
           cout << "L : " << L << " ; R : " << R << "\n"; 

        }
        /* code */
    }
    

    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string testStr;
    cin >> testStr;
    if(resolve(testStr)){
        cout << "YES\n" ;
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
