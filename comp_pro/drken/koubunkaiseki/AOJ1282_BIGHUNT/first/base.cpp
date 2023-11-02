#include <bits/stdc++.h>
using namespace std;

vector<string> get_input() {
    vector<string> lines;
    string S;
    while (cin >> S) {
        if (S == ".") break;
        lines.push_back(S);
    }
    return lines;
}

int solve(const vector<string> &lines) {
    map<char, long long> siz;  // siz[a] := 配列 a のサイズ
    map<pair<char, int>, long long> ma;  // ma[{a, i}] := a[i] の値
    for (int l = 0; l < lines.size(); ++l) {
        // "S=T" の形を読み解く
        string S = "", T = "";
        bool uhen = false;
        for (int j = 0; j < lines[l].size(); ++j) {
            if (lines[l][j] == '=') uhen = true;
            else if (!uhen) S += lines[l][j];
            else T += lines[l][j];
        }

        // 宣言の場合
        if (T == "") {
            char name = S[0];
            long long val = 0;
            for (int i = 2; i + 1 < S.size(); ++i) {
                val = (val * 10) + (S[i] - '0');
            }
            siz[name] = val;
        } else {
            // 左辺を処理
            vector<char> st;
            char left_char;
            long long left_ind = 0;
            for (auto c : S) {
                if (c == '[') continue;
                else if (c == ']') {
                    while (!st.empty()) {
                        // check range
                        if (left_ind >= siz[st.back()]) return l+1;

                        // check assignment
                        if (st.size() == 1) {
                            left_char = st[0];
                        }
                        else {
                            if (!ma.count({st.back(), left_ind})) return l+1;
                            left_ind = ma[{st.back(), left_ind}];
                        }
                        st.pop_back();
                    }
                }
                else if (isdigit(c)) {
                    left_ind = left_ind * 10 + (c - '0');
                }
                else {
                    st.push_back(c);
                }
            }

            // 右辺を処理
            long long right_val = 0;
            for (auto c : T) {
                if (c == '[') continue;
                else if (c == ']') {
                    while (!st.empty()) {
                        // check range
                        if (right_val >= siz[st.back()]) return l+1;

                        // check assignment
                        if (!ma.count({st.back(), right_val})) return l+1;
                        right_val = ma[{st.back(), right_val}];
                        st.pop_back();
                    }
                }
                else if (isdigit(c)) {
                    right_val = right_val * 10 + (c - '0');
                }
                else {
                    st.push_back(c);
                }
            }

            // 結果を処理
            ma[{left_char, left_ind}] = right_val;
        }
    }
    return 0;
}

int main() {
    vector<string> lines;
    while (!(lines = get_input()).empty()) {
        cout << solve(lines) << endl;
    }
}
