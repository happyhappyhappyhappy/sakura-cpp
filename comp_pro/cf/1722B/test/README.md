# 検証フォルダ

## 文字列置換

どうやら、すぐ思いついた[string.replace関数](https://cpprefjp.github.io/reference/string/basic_string/replace.html)には件名の様な機能は無いので、他の手を打つ必要がある。

[このサイト](https://marycore.jp/prog/cpp/std-string-replace-first-all/#std%3A%3Areplace%E9%96%A2%E6%95%B0%E3%81%AB%E3%82%88%E3%82%8B%E5%85%A8%E7%BD%AE%E6%8F%9B)に参考となる情報があったので、それを用いて一旦検証してみた。

1. [アルゴリズムライブラリのreplace関数](https://cpprefjp.github.io/reference/algorithm/replace.html)を利用。

    これはテンプレート関数になっているので、他の型でも応用可能。

[サンプル](./sample1.cpp)

実行結果

```text
変更前: YAMANAKA
変更後: YZMZNZKZ
```

1. [string.find関数](https://cpprefjp.github.io/reference/string/basic_string/find.html)を利用した場合。

[サンプル](./sample2.cpp)

```text
変更前: YAMANAKA
変更後: YBMBNBKB
```

## 文字列一致

[c++の仕様](https://cpprefjp.github.io/reference/string/basic_string/compare.html)

### 一致したとき、しなかった時の戻し値。

[作成プログラム](./compare.cpp)

* 一致した場合→0を返す

```text
文字列1: YAMANAKAKOJI
文字列2: YAMANAKAKOJI
戻し値: 0
```

* 一致しない場合→まずは0以外を返す

```text
文字列1: YAMANAKAKOJI
文字列2: YAMANAKEKOJI
戻し値: -4
```
