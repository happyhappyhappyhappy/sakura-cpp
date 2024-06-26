/* range_minimum_query_RAQ.cpp
    遅延評価セグメント木によって、区間での最小要素を管理する。区間加算型(RAQ)
    Range Add Query

    verified: AOJ DSL_2_H RMQ and RAQ
        http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja
 */

#include <bits/stdc++.h>
using namespace std;

/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    set(i,x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    add(a,b,x): 区間[a,b) の要素に x を加算。O(log(n))
    query(a,b): 区間 [a,b) での最小の要素を取得。O(log(n))
    find_rightest(a,b,x): [a,b) で x以下の要素を持つ最右位置を求める。O(log(n))
    find_leftest(a,b,x): [a,b) で x以下の要素を持つ最左位置を求める。O(log(n))
*/
template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat, lazy;
    RMQ(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, 0) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void set(int i, T x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }

    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == 0) return;  // 更新するものが無ければ終了
        if (k < n - 1) {           // 葉でなければ子に伝搬
            lazy[k * 2 + 1] += lazy[k];
            lazy[k * 2 + 2] += lazy[k];
        }
        // 自身を更新
        dat[k] += lazy[k];
        lazy[k] = 0;
    }

    void add(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] += x;
            eval(k);
        } else if (a < r && l < b) {                  // 一部区間が被る時
            add(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            add(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void add(int a, int b, T x) { add(a, b, x, 0, 0, n); }

    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return INF;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    T find_rightest(int a, int b, int x) { return find_rightest_sub(a, b, x, 0, 0, n); }  // 存在しなければ a-1
    T find_leftest(int a, int b, int x) { return find_leftest_sub(a, b, x, 0, 0, n); }    // 存在しなければ b
    T find_rightest_sub(int a, int b, int x, int k, int l, int r) {
        eval(k);
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn a-1
            return a - 1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != a - 1) {  // 右の部分木を見て a-1 以外ならreturn
                return vr;
            } else {  // 左の部分木を見て値をreturn
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
    T find_leftest_sub(int a, int b, int x, int k, int l, int r) {
        eval(k);
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn b
            return b;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) {  // 左の部分木を見て b 以外ならreturn
                return vl;
            } else {  // 右の部分木を見て値をreturn
                return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            }
        }
    }

    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < n; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    RMQ<int> rmq(n);
    for (int i = 0; i < n; i++) {
        rmq.set(i, 0);
    }
    rmq.build();

    vector<int> ans;
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            rmq.add(s, t + 1, x);
        } else if (c == 1) {
            int s, t;
            cin >> s >> t;
            ans.push_back(rmq.query(s, t + 1));
        }
    }
    for (auto i : ans) {
        cout << i << endl;
    }

    return 0;
}
