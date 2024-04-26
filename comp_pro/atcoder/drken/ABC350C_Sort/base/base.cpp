#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), where(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        --A[i];

        // 値 A[i] があるのは i 番目
        where[A[i]] = i;
    }

    // 左から i 番目に、値 i を持ってくる処理をする
    vector<pint> res;
    for (int i = 0; i <= N - 2; ++i) {
        // i 番目がすでに値 i なら何もしない
        if (A[i] == i) continue;

        // 値 i がある場所
        int j = where[i];

        // A[i] と A[j] を swap する
        swap(where[A[i]], where[A[j]]);
        swap(A[i], A[j]);
        res.emplace_back(i, j);
    }

    // 出力
    cout << res.size() << endl;
    for (auto [i, j] : res) {
        cout << i+1 << " " << j+1 << endl;
    }
}
