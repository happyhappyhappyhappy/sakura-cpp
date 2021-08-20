# \[ABC129C\]\<Typical Stairs\>

## [問題のURL](https://atcoder.jp/contests/abc129/tasks/abc129_c)

## [解説のURL](https://atcoder.jp/contests/abc129/tasks/abc129_c/editorial)

## [この問題の結果](https://atcoder.jp/contests/abc129/submissions?f.Task=abc129_c&f.LanguageName=&f.Status=AC&f.User=)

## [作成結果2021年8月20日](https://atcoder.jp/contests/abc129/submissions/25167311)

しかし、このメッセージを見るに

```plaintext
./Main.cpp: In function ‘int main(int, const char**)’:
./Main.cpp:69:14: warning: unused parameter ‘argc’ [-Wunused-parameter]
   69 | int main(int argc, char const *argv[])
      |          ~~~~^~~~
./Main.cpp:69:32: warning: unused parameter ‘argv’ [-Wunused-parameter]
   69 | int main(int argc, char const *argv[])
      |                    ~~~~~~~~~~~~^~~~~~
```

`main()`関数はvoid型にした方が良さそうだ。

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----
ヒント

* N段目に行くのは何通りかを格段で作成するこれにDPを使えばいい、とのことだが･･･

* 自分でシミュレーションしてみると`DP[j] = DP[j-1] + DP[j-2]`で解決しそう。
  * もちろん壊れている所は`DP[j] = 0`で表現。

* DPである必然性はあるのか。
