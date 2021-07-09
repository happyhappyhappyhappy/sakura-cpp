#include <bits/stdc++.h>

using namespace std;
/**
int solve(){
    result=0;
    return result;
}
**/
int main(int argc, char const *argv[])
{
    int p_count;
    cin >> p_count;
    vector<int> v(p_count);
    for(int i=0;i<p_count;i=i+1){
        for(int &e:v){
            cin >> e;
        }
    } 
    cout << v[2];
    return 0;
}
