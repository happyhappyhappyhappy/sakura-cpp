# \[ABC015D\]\<高橋くんの苦悩\>

* [これの類題](https://qiita.com/drken/items/dc53c683d6de8aeacf5a#d-%E5%95%8F%E9%A1%8C---knapsack-1)

## [問題のURL](https://atcoder.jp/contests/abc015/tasks/abc015_4)

## 解説のURL無し

## [他に解説無いか…](https://www.google.com/search?q=ABC015D&oq=ABC015D&aqs=chrome..69i57j69i60l2.5218j0j15&sourceid=chrome&ie=UTF-8)

* [その1](https://qiita.com/sifi_border/items/8b8a802c7e95d5bb71f1)
* [その2](https://mmxsrup.hatenablog.com/entry/2016/09/18/230648)

## [この問題の結果:c++](https://atcoder.jp/contests/abc015/submissions?f.Task=abc015_4&f.LanguageName=C%2B%2B&f.Status=AC&f.User=)

## [セレクターのc++解答](https://atcoder.jp/contests/abc015/submissions/1101781)

* これは3つめの配列要素が重要度になっている＋DPの内容が広さなので、その1と2で比較すると危険

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 

 ---->

-----

## ヒント

* DPの配列は三次元「総枚数」「今まで何枚使ったか」「今までの利用幅はいくつか」

## [自分の答(NG)](https://atcoder.jp/contests/abc015/submissions/27421357)

* 全部の問題でなく一部の問題なので怖い

* 何か[これ](https://mmxsrup.hatenablog.com/entry/2016/09/18/230648)がわかりやすいっぽい。ループで```DP=-1```となるのは難しいところだが
    * ```DP=-∞```にすればわざわざ飛ばす必要もない気がする。ということでこれを写経してみる
* [解説サーチ](https://duckduckgo.com/?q=%E9%AB%98%E6%A9%8B%E5%90%9B%E3%81%AE%E8%8B%A6%E6%82%A9&t=h_&ia=web)

-----

## [自分の答え(OK)](https://atcoder.jp/contests/abc015/submissions/27497270)

* 前の答えではDP値のデフォルトを```-1```にしたためそれが敗者復活になる感じで最終的に採用されてしまったようだ
    * 今回は```-∞```にして対応できた。
