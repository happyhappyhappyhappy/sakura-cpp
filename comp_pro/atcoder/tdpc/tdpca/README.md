# \[TDPC-A\]\<コンテスト\>

* [これの類題](https://qiita.com/drken/items/dc53c683d6de8aeacf5a#d-%E5%95%8F%E9%A1%8C---knapsack-1)

## [問題のURL](https://atcoder.jp/contests/tdpc/tasks/tdpc_contest)

## [解説のURL](https://atcoder.jp/contests/tdpc/editorial/756)

## [解説中にあったpython版の回答](https://atcoder.jp/contests/tdpc/submissions/20186239)←分からん

## [この問題の結果:c++](https://atcoder.jp/contests/tdpc/submissions?f.Task=tdpc_contest&f.LanguageName=C%2B%2B&f.Status=AC&f.User=)

## [セレクターのc++解答](https://drken1215.hatenablog.com/entry/2020/12/21/153600)

* 考え方としては、無ければ無視、有ればつぎの変数に引き継ぎと次の問題を加えて引き継ぐ感じかな。

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----
ヒント

* この問題は二次元DPにするのみで大きさの比較は特に要らない、というか0と1の論理和で求めてしまう。

* 配列の一番目の要素は何個目の得点を加えたかを示し、二番目の要素は足された合計を示している
  * 両者の判定をbool値を利用して作成出来る得点、作成出来ない得点を区別している→最終的には全部の問題確認が終了したところで作成出来る得点を数え上げている。

## [自分の答](https://atcoder.jp/contests/tdpc/submissions/26430786)
