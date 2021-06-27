#include<bits/stdc++.h>
/**
    Problem: https://codeforces.com/problemset/problem/1512/B
    Answer : https://codeforces.com/blog/entry/89535
 **/
using namespace std;

int main(int argc, char const *argv[])
{
    vector<pair<int,int>> p;

    long long n;
    cin >> n;
    vector<string> line(n);
    for (int i = 0; i < n; i++)
    {
        cin >> line[i];        
        /* code */
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /* code */
            if(line[i][j] == '*'){
                p.push_back({i,j});
            }
        }
        
        /* code */
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << line[i] << endl;
    }
    cout << "* size is " << p.size() << endl;
//    cout << "END" << endl;

    return 0;
}
