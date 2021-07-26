#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

bool dictCheck(map<char,int> &dict){
    for (auto i = dict.begin(); i != dict.end(); i++)
    {
        cout << "Char " << i->first 
        << "\t" << i->second << "\n";
    }
    return true;
}
bool oneIndextoZero(int &from_pos,int &end_pos){
    from_pos = from_pos - 1;
    end_pos = end_pos - 1;
    return true;
}
bool make_dict(map<char,int> &emp_dict){
    bool can_do=false;
 //   cout << "Problem String: " << problem_str << "\n";
    int multi = 1;
    // ここで与えられた文字列から辞書を作成する
    for (int i = int('a'); i <= int('z'); i++)
    {
        emp_dict.insert(make_pair(char(i),multi));
        multi = multi + 1;
        can_do = true;
    }
    // can_do=true;
    return can_do;
}
int solve(string problem_str,map<char,int> &dict,int from_pos,int to_pos){
    // cout << "From : " << from_pos-1 
    // << " -> To : " << to_pos-1 << "\n";
    int result=0;
    oneIndextoZero(from_pos,to_pos);
    for(int i=from_pos;i < to_pos+1;i++){
        result = result + dict.at(problem_str.at(i));
    }

    return result;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<char,int> dict;
    int tmp,problem_cnt; // 一行目から読み取る数値
    string problem_str;
    // vector<vector<int>> q_pos;
    // ↑ 問題の文字列が解析できたら都度main関数内で処理するようロジック設定
    cin >> tmp >> problem_cnt;
    cin >> problem_str;
    if(make_dict(dict)==false){
        cout << "Error String:" << problem_str << "\n";
        return 2;
    }
    /**
      for (auto iter=dict.begin(); iter != dict.end(); iter++)
    {
        cout << "char : " << iter->first << " , multi : " << iter->second << "\n";
    }
    **/
    // dictCheck(dict);    

    for (int i = 0; i < problem_cnt; i++)
    {
        int from_pos,to_pos;
        cin >> from_pos >> to_pos;
        int answer = solve(problem_str,dict,from_pos,to_pos);
        cout << answer << "\n";        
    }
    return 0;
}
