#ifdef DEBUG
#define _GLIBXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
// 逐次読み取り法へ変更 2021/07/26
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tmp,problem_cnt; // 一行目から読み取る数値
    string problem_str;
    // vector<vector<int>> q_pos;
    // ↑ 問題の文字列が解析できたら都度main関数内で処理するようロジック設定
    cin >> tmp >> problem_cnt;
    cin >> problem_str;
    for (int i = 0; i < problem_cnt; i++)
    {
        int from_pos,to_pos,from_pos_0,to_pos_0;
        int answer=0;
        cin >> from_pos >> to_pos;
        from_pos_0 = from_pos - 1;
        to_pos_0 = to_pos-1;
        for (int j = from_pos_0; j <= to_pos_0; j++)
        {
            int a_code = int('a');
            int now_code = int(problem_str.at(j));
            int add_cnt = now_code - a_code + 1;
            answer = answer+add_cnt;
        }
        cout << answer << "\n";        
    }
    return 0;
}
