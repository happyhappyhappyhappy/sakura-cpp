#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif // DEBUG
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

int point_set(vector<pair<int,int>> &point){

    return 0;
}
int line_process(vector<string> &line,int l){
    vector<pair<int,int>> point;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if(line[i][j] == '*'){
                point.push_back({i,j});
            }
        }
        
    }
    point.push_back(point[0]);
    point.push_back(point[1]);
    point_set(point);    
    return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int stringlength;
        cin >> stringlength;
        vector<string> stringLine(stringlength);
        for(int j=0; j<stringlength; j=j+1){
            cin >> stringLine[j];
        }
        line_process(stringLine,stringlength);
        for(int j=0;j<stringlength;j=j+1){
            cout << stringLine[j] << "\n";
        }
    }
    
    return 0;
}
