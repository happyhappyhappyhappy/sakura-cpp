#ifdef DEBUG
#define _GLIBXX_DEBUG_
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // おまじない
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector<pair<int,int>> point;
    cin >> n;
    vector<string> line(n);
    for (int i = 0; i < n; i++)
    {
        cin >> line[i];
    }
    
    for (int i = 0; i < n; i=i+1)
    {
        for (int j = 0; j < n; j=j+1)
        {
            if(line[i][j]=='*'){
                point.push_back({i,j});
            }
        }
        
    }
    for(int i=0;i < point.size();i=i+1){
        cout << i << " : " << point[i].first << " , " 
        << point[i].second << "\n"; 
    }
    point.push_back(point[0]);
    point.push_back(point[1]);
    if(point[0].second == point[1].second){
        point[2].second = (point[0].second + 1) % n;
        point[3].second = (point[1].second + 1) % n;
    }
    cout << "↓" << "\n";
    for (int i = 0; i < point.size(); i = i + 1)
    {
        cout << i << " : " << point[i].first << " , " << 
        point[i].second << "\n";
    }
    // 更新
    line[point[2].first][point[2].second] = '*';
    line[point[3].first][point[3].second] = '*';
    // 出力
    for (int i = 0; i < n; i++)
    {   
        // line[i]で出力させちゃえ
        // cin << ;
        // for (int j = 0; i < n; j++)
        // {
            
        // }
        
    }
    
    return 0;
}
