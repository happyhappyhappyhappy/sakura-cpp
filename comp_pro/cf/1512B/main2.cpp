#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif // DEBUG
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

int point_set(vector<pair<int,int>> &point, int l_n){
    /**  もらった「*」座標の結果
  for (int i = 0; i < point.size(); i++)
    {
        cout << i+1 << "番目: " << point[i].first
        << " , " << point[i].second << "\n"; 
    }
    **/
   if(point[0].first == point[1].first){
       point[2].first = (point[2].first+1) % l_n; 
       point[3].first = (point[3].first+1) % l_n;
   }
   else{
    if(point[0].second == point[1].second){
        point[2].second = (point[2].second+1) % l_n;
        point[3].second = (point[3].second+1) % l_n;
    }   
    else{
        swap(point[2].second,point[3].second);
    }    
   }   
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
    point_set(point,l);    
    for (int i = 0; i < point.size(); i++)
    {
        line[point[i].first][point[i].second] = '*';
    }
    
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
//        cout << i+1 << "番目:" << '\n';
        int stringlength;
        cin >> stringlength;
//        cout << stringlength << "\n";
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
