# \[TDPC-D\]\<サイコロ\>

* [これの類題](https://qiita.com/drken/items/dc53c683d6de8aeacf5a#d-%E5%95%8F%E9%A1%8C---knapsack-1)

## [問題のURL](https://atcoder.jp/contests/tdpc/tasks/tdpc_dice)

## 解説のURL無し

## [他に解説無いか…](https://duckduckgo.com/?q=tdpc+d+%E3%82%B5%E3%82%A4%E3%82%B3%E3%83%AD&t=h_&ia=web)

* [その1](https://suikaba.hatenablog.com/entry/2017/07/03/024221)

## [この問題の結果:c++](https://atcoder.jp/contests/tdpc/submissions?f.Task=tdpc_dice&f.LanguageName=C%2B%2B&f.Status=AC&f.User=)

## [セレクターのc++解答](https://atcoder.jp/contests/tdpc/submissions/1813122)

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 

 ---->

-----
ヒントや各種参考となったページ

* [map構造体とは？サンプルで説明](https://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/)
* [mapとは](https://cpprefjp.github.io/reference/map/map.html)
* [#defineは使わない方が良い](https://qiita.com/elipmoc101/items/01003c82dbd2e464a071)
* [constexprの使い方](https://cpprefjp.github.io/lang/cpp11/constexpr.html)

## [自分の答(未完)](https://atcoder.jp/)

-----

## TODO

* `a[x] =+ b[x]/6`は`a[x] = ( a[x] + b[x] ) / 6`か`a[x] = a[x] + (b[x] / 6`か調べてみる。ちなみに`6`はサイコロの目の数
    * 結果`a=a+(b/6)`
* [参考にするページ](https://ben2suzuka.hatenablog.com/entry/8)
    * まずはこれで打ち込んでみる
    * `10^18`が2の何乗とか調べるには`log10*18/log`を使う
* $6^{100}$が2,3,5の何乗以下で収集できるのか確認する[ソース](./sample/youso.cpp)

## 問題を解くヒント(katex方式で書いてあるのでプラングインが必要)

* 4次元のDPテーブルを利用
    * $DP[サイコロを振った数][そのときの(以下略)2の倍数][3の倍数][5の倍数]$
    * 各倍数に必要な要素は先ほどの計算より、$2^{259}$,$3^{164}$,$5^{112}$
        * と分かるので最初は全部300にしてしまう
        * しかし[エラーがでる](http://www.iimc.kyoto-u.ac.jp/ja/faq/comp/hpc/-02_2.html)⇒要はメモリ使用量が2Gを超える列になる
            * 上のリンクではオプション付ける指示があるがそういうややこしいことはさせないはず
            * ここは$10^{18}$で我慢するしか無い
            * [結果](./sample/youso2.cpp)⇒$10^{18}=2^{60},3^{38},5^{26}$

## 結果

* [1回目失敗](https://atcoder.jp/contests/tdpc/submissions/28260388)
    * よく見たらデバッグ用の出力もした。それを削除してもう一回出し直し
* [1回目成功](https://atcoder.jp/contests/tdpc/submissions/28260437)
