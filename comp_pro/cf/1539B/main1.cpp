#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

bool make_dict(map<char,int> &emp_dict,string problem_str){
    bool can_do=false;
    cout << "Problem String: " << problem_str << "\n";
    int position = 0;
    // ここで与えられた文字列から辞書を作成する
    for (int i = 0; i < problem_str.size(); i++)
    {
        if(emp_dict.count(problem_str.at(i))==0){

        }
        /* code */
    }
    
    // can_do=true;
    return can_do;
}
int solve(map<char,int> &dict,int from_pos,int to_pos){
    cout << "From : " << from_pos-1 
    << " -> To : " << to_pos-1 << "\n";
    int result=0;
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
    if(make_dict(dict,problem_str)==false){
        cout << "Error String:" << problem_str << "\n";
        return 2;
    }
    for (int i = 0; i < problem_cnt; i++)
    {
        int from_pos,to_pos;
        cin >> from_pos >> to_pos;
        int answer = solve(dict,from_pos,to_pos);
        cout << answer << "\n";        
    }
    return 0;
}
