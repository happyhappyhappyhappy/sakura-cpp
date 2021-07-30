#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

class my_container {
    public:
        int *begin(){
            return &buf[0];
        }
        int *end(){
        return &buf[5];
        }
    private:
    int buf[5] = {21,22,23,24,25};
};


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int array[5] = {1,2,3,4,5};
    cout << "For int[5]:  " << "\n";
    for (auto& e : array)
    {
        cout << " " << e << "\n";
    }
    vector<int> vec={10,11,12,13};
    cout << "For vector<int> :" << "\n";
    for(auto& e:vec){
        cout << " " << e << "\n";
    }
    my_container mc;
    cout << "For my_container: \n" ; 
    for (auto& e:mc){
        cout << " " << e << "\n";
    }
    // default 
    vector<int> vec2={1,3,5,7,8};
    cout << "C++03 Used pattern: \n";
    for(vector<int>::const_iterator it=vec2.begin(),e=vec2.end();
    it != e;++it)
    {
        cout << " " << *it << "\n";
    }
    
    return 0;
}
