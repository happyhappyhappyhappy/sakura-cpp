# \[ただ足し合うだけの計算時間を確認しよう\]

## きっかけ

`for(int j=0;j<N;j++)` では最初のDP初期化が遅かったため

-----
ヒント

* 参考ページ
    * [仕様](https://cpprefjp.github.io/reference/chrono.html)
    * [使い方](https://qiita.com/hurou927/items/a2d63837e731713c7a22)

-----
結果:意外と少ない？？？

```txt
 i++   : 158 μs
 ++i   : 323 μs
 i=i+1 : -1.63628e+12 μs                               
```
