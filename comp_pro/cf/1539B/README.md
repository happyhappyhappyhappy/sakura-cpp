# \[1539B\]LOVE SONG

## [問題のURL](https://codeforces.com/problemset/problem/1539/B)
## [解説のURL](https://codeforces.com/blog/entry/91906)←ヒントのみにとどまっている

-----
ヒント

* まずはどのアルファベットが何番目に出たかで分ける
→終了
* 問題の出し方を見てこれは1indexなので0-indexにする
→問題のフォーマットを見る限り行数＋データにする
* 0-indexを見て正しく文字列を作れるかチェック
  * よく考えると、指定した位置から位置まで逐一調べるだけでも良さそうな気もしてきた

-----
# 完了したが大きいデータでTLEが起こる
[結果1](https://codeforces.com/problemset/submission/1539/123788108)
[結果2](https://codeforces.com/contest/1539/submission/123884877)

* 累積和を使って見ようか
[他人の解答](https://codeforces.com/contest/1539/status/B)


* \[問題番号\\status\\問題コード\\]で見に行ける

* [結果](https://codeforces.com/contest/1539/submission/124075767)
  * 段違いに実行時間が異なる
-----
### 参考リンク
* [Mapの使い方](http://vivi.dyndns.org/tech/cpp/map.html)
* [文字列関数を使いこなす](https://qiita.com/MasahiroBW/items/3f56b22a079cd3272cd3)
* [make_pair関数](https://cpprefjp.github.io/reference/utility/make_pair.html)
* [累積和→重要](https://qiita.com/drken/items/56a6b68edef8fc605821)
