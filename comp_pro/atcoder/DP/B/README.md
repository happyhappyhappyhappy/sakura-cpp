# \[B\]\<Flog2\>

## [問題のURL](https://atcoder.jp/contests/dp/tasks/dp_b)

## [解説のURL](https://qiita.com/drken/items/dc53c683d6de8aeacf5a#b-%E5%95%8F%E9%A1%8C---frog-2)

## [この問題の結果](https://atcoder.jp/contests/dp/submissions?f.Task=dp_b&f.LanguageName=C%2B%2B&f.Status=AC&f.User=)

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----

ヒント

1. 無限大を正しく確認する
    * `1 << 62`の様に左不等号を使う

1. for文を使う時は(与える型DPの場合)一番目は0からオブジェクトの数まで、二番目は1からオブジェクトの数＋1まで

1. typedefはC++11ではオワコン[参考リンク](https://qiita.com/Linda_pp/items/44a67c64c14cba00eef1)

-----

## 自分の提出

### [与える型DP→OK](https://atcoder.jp/contests/dp/submissions/25809798)

### [与える型DP→NG](https://atcoder.jp/contests/dp/submissions/25740376)

    * NGの特徴は`LIMITMAX` を`1LL<<15`から`1LL<<61`と値を大幅に増加させたこと。
-----
