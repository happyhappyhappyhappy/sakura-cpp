# \[1547B\]\< Alphabetical Strings\>

## [問題のURL](https://codeforces.com/problemset/problem/1547/B)

## [解説のURL](https://codeforces.com/blog/entry/92715)

## [この問題の結果](https://codeforces.com/contest/1547/status/B)

<!----
PROBLEMS→問題番号一覧→回答者数→accepted 
----->

-----

## ヒント

* とりあえず'a'を見つけて、後は右と左で探索

-----

1. [size_t](https://ota42y.com/blog/2014/11/08/size-t/)
    * マニュアル見てもよく分からない
        * どうやら文字列の有無を確認するには単純にnullとは書かずstring::nposで表現する用だ(決め打ちは出来ない)
1. [String.find()](https://cpprefjp.github.io/reference/string/basic_string/find.html)
