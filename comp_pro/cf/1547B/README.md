# \[1547B\]\< Alphabetical Strings\>

## [問題のURL](https://codeforces.com/problemset/problem/1547/B)

## [解説のURL](https://codeforces.com/blog/entry/92715)

## [この問題の結果](https://codeforces.com/contest/1547/status/B)

## 完了

* [投稿リンク](https://codeforces.com/problemset/submission/1547/125186067)

<!----
PROBLEMS→問題番号一覧→回答者数→accepted 
----->

-----

## ヒント

* とりあえず'a'を見つけて、後は右と左で探索

## 考えたところ

* 模範解答にはmin,max関数を使っているがここでは自動的に値を切り替える独自の関数を作成

* もしかしたら入力はscanf,出力はputとすればもっと速くなる＋メモリ使わないか

-----

1. [size_t](https://ota42y.com/blog/2014/11/08/size-t/)
    * マニュアル見てもよく分からない
        * どうやら文字列の有無を確認するには単純にnullとは書かずstring::nposで表現する用だ(決め打ちは出来ない)
1. [String.find()](https://cpprefjp.github.io/reference/string/basic_string/find.html)
