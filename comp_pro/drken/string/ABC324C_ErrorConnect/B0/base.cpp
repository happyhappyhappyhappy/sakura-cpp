#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string T;
    cin >> N >> T;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) cin >> S[i];

    vector<int> res;
    for (int i = 0; i < N; ++i) {
        // S[i] と T の文字数が 2 文字以上異なっていたらダメ
        if (abs((int)S[i].size() - (int)T.size()) >= 2) continue;

        // S[i] の先頭からと末尾から T と一致する文字数を求める
        int pre = 0, suf = 0;
        for (pre = 0; pre < min(S[i].size(), T.size()); ++pre) {
            if (S[i][pre] != T[pre]) break;
        }
        for (suf = 0; suf < min(S[i].size(), T.size()); ++suf) {
            if (S[i][S.size()-1-suf] != T[T.size()-1-suf]) break;
        }

        if (pre + suf >= min(S.size(), T.size())) res.push_back(i);
        else if (S.size() == T.size() && pre + suf + 1 == S.size()) res.push_back(i);
    }
    cout << res.size() << endl;
    for (auto v : res) cout << v+1 << " ";
    cout << endl;
}
